#pragma once


class taskflowLib {
public:
    // Constructor/Destructor
    taskflowLib();
    ~taskflowLib();

    // Core API
    void* create_taskflow();
    void* create_executor();
    void* task_definition(const char* name, void (*func)());
    void add_dependency(void* prev, void* next);
    void execute();

    // Optional API
    void set_name(const char* name);
    int num_tasks();
    bool is_empty();

private:
    void* taskflow_ptr;
    void* executor_ptr;
};