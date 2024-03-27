#include <cstdio>
#include <string>
#include <taskflow/taskflow.hpp> 
#include "lib.hpp"
#include "taskflow/core/task.hpp"



void taskflowLib::create_taskflow(){
  taskflow_ptr = new tf::Taskflow();
}

void taskflowLib::create_execution(){
  executor_ptr = new tf::Executor();
}

taskflowLib::taskflowLib(){
    create_taskflow();
    create_execution();
}

// task definition
void* taskflowLib::task_definition(std::string name, void (*func)()){
    tf::Taskflow *taskflow = (tf::Taskflow *) taskflow_ptr;    
    if (!taskflow) {
        return nullptr; 
    }
    auto task = taskflow->emplace(func).name(name);
    // copy the task to the heap
    auto t = new tf::Task(task);
  
    return (void*) t;
}
// dependency definition
void taskflowLib::add_dependency(void* prev, void* next){
    tf::Task *t1 = (tf::Task*) (prev);
    tf::Task *t2 = (tf::Task*) (next);
    t1->precede(*t2);
}

// execution
void taskflowLib::execute(){
    tf::Taskflow *taskflow = (tf::Taskflow *) taskflow_ptr;
    tf::Executor *executor = (tf::Executor *) executor_ptr;
    executor->run(*taskflow).wait();
}

// int main(){
  
//     auto myTaskflowLib = taskflowLib();

//     auto A = myTaskflowLib.task_definition("A", [](){printf("A\n");});
//     auto B = myTaskflowLib.task_definition("B", [](){printf("B\n");});
//     auto C = myTaskflowLib.task_definition("C", [](){printf("C\n");});

//     myTaskflowLib.add_dependency(C, B);
//     myTaskflowLib.add_dependency(B, A);

//     myTaskflowLib.execute();    

//   return 0;
// }