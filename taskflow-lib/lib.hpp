#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Opaque types - define the structs to make them complete types
struct TaskflowLib;
struct TaskWrapper {
    void* task;  // Will hold tf::Task* internally
};

// Core API
TaskflowLib* taskflow_create();
void taskflow_destroy(TaskflowLib* tf);
TaskWrapper* taskflow_create_task(TaskflowLib* tf, const char* name, void (*func)());
void taskflow_add_dependency(TaskWrapper* from, TaskWrapper* to);
void taskflow_execute(TaskflowLib* tf);

// Optional API
void taskflow_set_name(TaskflowLib* tf, const char* name);
int taskflow_num_tasks(TaskflowLib* tf);
int taskflow_is_empty(TaskflowLib* tf);

#ifdef __cplusplus
}
#endif