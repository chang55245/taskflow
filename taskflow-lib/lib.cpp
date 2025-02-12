#include <cstdio>
#include <string>
#include "lib.hpp"
#include <taskflow/taskflow.hpp>  // Include the full taskflow header

taskflowLib::taskflowLib() : taskflow_ptr(nullptr), executor_ptr(nullptr) {
    create_taskflow();
    create_executor();
}

taskflowLib::~taskflowLib() {
    if(taskflow_ptr) {
        delete static_cast<tf::Taskflow*>(taskflow_ptr);
    }
    if(executor_ptr) {
        delete static_cast<tf::Executor*>(executor_ptr);
    }
}

void* taskflowLib::create_taskflow() {
    if(!taskflow_ptr) {
        taskflow_ptr = new tf::Taskflow();
    }
    return taskflow_ptr;
}

void* taskflowLib::create_executor() {
    if(!executor_ptr) {
        executor_ptr = new tf::Executor();
    }
    return executor_ptr;
}

// task definition
void* taskflowLib::task_definition(const char* namechar, void (*func)()) {
    tf::Taskflow* taskflow = static_cast<tf::Taskflow*>(taskflow_ptr);
    if(!taskflow) return nullptr;

    std::string name = namechar ? std::string(namechar) : "";
    auto task = taskflow->emplace(func).name(name);
    return new tf::Task(task);
}

// dependency definition
void taskflowLib::add_dependency(void* prev, void* next) {
    if(!prev || !next) return;
    
    auto task1 = static_cast<tf::Task*>(prev);
    auto task2 = static_cast<tf::Task*>(next);
    task1->precede(*task2);
}

// execution
void taskflowLib::execute() {
    auto taskflow = static_cast<tf::Taskflow*>(taskflow_ptr);
    auto executor = static_cast<tf::Executor*>(executor_ptr);
    if(taskflow && executor) {
        executor->run(*taskflow).wait();
    }
}

void taskflowLib::set_name(const char* name) {
    if(!taskflow_ptr || !name) return;
    auto taskflow = static_cast<tf::Taskflow*>(taskflow_ptr);
    taskflow->name(name);
}

int taskflowLib::num_tasks() {
    if(!taskflow_ptr) return 0;
    auto taskflow = static_cast<tf::Taskflow*>(taskflow_ptr);
    return static_cast<int>(taskflow->num_tasks());
}

bool taskflowLib::is_empty() {
    if(!taskflow_ptr) return true;
    auto taskflow = static_cast<tf::Taskflow*>(taskflow_ptr);
    return taskflow->empty();
}