#pragma once
#include <cstring>
#include <cstdlib>
#ifdef __cplusplus
extern "C" {
#endif

// Opaque types
struct TaskflowLib;
struct TaskWrapper {
    void* task;
};

// Simple argument structure
struct TaskArg {
    void* ptr;         // Pointer to any type
    bool is_value;     // true if data is stored by value, false if it's a pointer
};

struct TaskArgs {
    TaskArg* args;     // Dynamic array of arguments
    size_t num_args;   // Number of arguments
};

// Core API
TaskflowLib* taskflow_create();
void taskflow_destroy(TaskflowLib* tf);

// Argument management
TaskArgs* create_task_args(size_t num_args);
void destroy_task_args(TaskArgs* args);
void set_task_arg_ptr(TaskArgs* args, size_t index, void* ptr);
void set_task_arg_value(TaskArgs* args, size_t index, void* value, size_t size);

// Task creation and management
TaskWrapper* taskflow_create_task(
    TaskflowLib* tf, 
    const char* name, 
    void (*func)(TaskArgs*),
    TaskArgs* args
);
void taskflow_add_dependency(TaskWrapper* from, TaskWrapper* to);
void taskflow_execute(TaskflowLib* tf);

// Optional API
void taskflow_set_name(TaskflowLib* tf, const char* name);
int taskflow_num_tasks(TaskflowLib* tf);
int taskflow_is_empty(TaskflowLib* tf);

#ifdef __cplusplus
}
#endif