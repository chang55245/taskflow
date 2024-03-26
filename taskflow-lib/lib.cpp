#include <taskflow/taskflow.hpp>  // Taskflow is header-only
#include "lib.hpp"



void taskflowLib::create_taskflow(){
  taskflow_ptr = new tf::Taskflow();
}

void taskflowLib::create_execution(){
  executor_ptr = new tf::Executor();
}

inline taskflowLib::taskflowLib(){
    create_taskflow();
    create_execution();
}

// task definition
void taskflowLib::task_definition(){
    tf::Taskflow *taskflow = (tf::Taskflow *) taskflow_ptr;
    tf::Task A = taskflow->emplace([](){}).name("A");  
}

int main(){
  
    auto myTaskflowLib = taskflowLib();

    
    tf::Executor executor;
    tf::Taskflow taskflow;

tf::Task A = taskflow.emplace([](){}).name("A");  
tf::Task C = taskflow.emplace([](){}).name("C");  
tf::Task D = taskflow.emplace([](){}).name("D");  

tf::Task B = taskflow.emplace([] (tf::Subflow& subflow) { 
    tf::Task B1 = subflow.emplace([](){}).name("B1");  
    tf::Task B2 = subflow.emplace([](){}).name("B2");  
    tf::Task B3 = subflow.emplace([](){}).name("B3");  
    B3.succeed(B1, B2);  // B3 runs after B1 and B2
}).name("B");

A.precede(B, C);  // A runs before B and C
D.succeed(B, C);  // D runs after  B and C
                                      
  executor.run(taskflow).wait(); 

  return 0;
}