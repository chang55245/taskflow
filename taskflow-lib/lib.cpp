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

TaskArgs* create_task_args(size_t num_args) {
    TaskArgs* args = new TaskArgs;
    args->args = new TaskArg[num_args];
    args->num_args = num_args;
    // Initialize all args
    for(size_t i = 0; i < num_args; i++) {
        args->args[i].ptr = nullptr;
        args->args[i].size = 0;
    }
    return args;
}

void destroy_task_args(TaskArgs* args) {
    if (args) {
        // Free any values that were stored by copy
        for(size_t i = 0; i < args->num_args; i++) {
            if (args->args[i].ptr) {
                free(args->args[i].ptr);
            }
        }
        delete[] args->args;
        delete args;
    }
}

void set_task_arg_ptr(TaskArgs* args, size_t index, void* ptr, int size) {

    if (index >= args->num_args) return;
    // Free any existing value storage
    if (args->args[index].ptr) {
        free(args->args[index].ptr);
        free(args->args[index].private_copy);
    }
    args->args[index].ptr = ptr;
    args->args[index].size = size;
}

void taskflow_copy_back(TaskArgs* args) {
    if (!args) return;
    
    for(size_t i = 0; i < args->num_args; i++) {
        if (args->args[i].ptr && args->args[i].private_copy && args->args[i].size > 0) {
            memcpy(args->args[i].ptr, args->args[i].private_copy, args->args[i].size);
        }
        free(args->args[i].private_copy);
    }
}

TaskWrapper* taskflow_create_task(
    TaskflowLib* tf, 
    const char* name, 
    void (*func)(TaskArgs*),
    TaskArgs* args
) {
    if (!tf || !tf->taskflow) return nullptr;
    
    // Deep copy of arguments
    TaskArgs* args_copy = create_task_args(args->num_args);
    for(size_t i = 0; i < args->num_args; i++) {
        
        // For pointers, just copy the pointer
        args_copy->args[i].ptr = args->args[i].ptr;
        args_copy->args[i].private_copy = malloc(args->args[i].size);
        memcpy(args_copy->args[i].private_copy, args->args[i].ptr, args->args[i].size);
        args_copy->args[i].size = args->args[i].size;
        
    }
    
    auto task = tf->taskflow->emplace([func,name, args_copy]() {
        printf("running task:%s \n",name);
        func(args_copy);
        printf("task %s finished\n", name);
    });
    
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