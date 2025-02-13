#include <cstdio>
#include <string>
#include "lib.hpp"
#include <taskflow/taskflow.hpp>  // Include the full taskflow header

struct TaskflowLib {
    tf::Taskflow* taskflow;
    tf::Executor* executor;
};

extern "C" {

TaskflowLib* taskflow_create() {
    TaskflowLib* tf = new TaskflowLib();
    tf->taskflow = new tf::Taskflow();
    tf->executor = new tf::Executor();
    return tf;
}

void taskflow_destroy(TaskflowLib* tf) {
    if (tf) {
        delete tf->taskflow;
        delete tf->executor;
        delete tf;
    }
}

TaskWrapper* taskflow_create_task(TaskflowLib* tf, const char* name, void (*func)()) {
    if (!tf || !tf->taskflow) return nullptr;
    
    auto task = tf->taskflow->emplace(func);
    if (name) {
        task.name(name);
    }
    
    TaskWrapper* wrapper = new TaskWrapper;
    wrapper->task = new tf::Task(task);
    return wrapper;
}

void taskflow_add_dependency(TaskWrapper* from, TaskWrapper* to) {
    if (!from || !to) return;
    
    auto* task1 = static_cast<tf::Task*>(from->task);
    auto* task2 = static_cast<tf::Task*>(to->task);
    task1->precede(*task2);
}

void taskflow_execute(TaskflowLib* tf) {
    if (!tf || !tf->taskflow || !tf->executor) return;
    tf->executor->run(*tf->taskflow).wait();
}

void taskflow_set_name(TaskflowLib* tf, const char* name) {
    if (!tf || !tf->taskflow || !name) return;
    tf->taskflow->name(name);
}

int taskflow_num_tasks(TaskflowLib* tf) {
    if (!tf || !tf->taskflow) return 0;
    return static_cast<int>(tf->taskflow->num_tasks());
}

int taskflow_is_empty(TaskflowLib* tf) {
    if (!tf || !tf->taskflow) return 1;
    return tf->taskflow->empty() ? 1 : 0;
}

}