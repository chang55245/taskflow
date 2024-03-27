#include "string"
class taskflowLib {
public:
    void create_taskflow();
    void create_execution();
    void task_definition(std::string name, void (*func)());
    void add_dependency(void* prev, void* next);
    void execute();

    void * taskflow_ptr;
    void * executor_ptr;
    taskflowLib();
};

// class taskLib
// {

// };