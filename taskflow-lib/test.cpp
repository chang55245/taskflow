#include <stdio.h>
#include "lib.hpp"

void task_with_multiple_args(TaskArgs* args) {
    // Access arguments as pointers
    int* int_ptr = (int*)args->args[0].ptr;
    float* float_ptr = (float*)args->args[1].ptr;
    const char* str_ptr = (const char*)args->args[2].ptr;
    int* array_ptr = (int*)args->args[3].ptr;
    
    printf("Int value: %d\n", *int_ptr);
    printf("Float value: %.2f\n", *float_ptr);
    printf("String: %s\n", str_ptr);
    printf("Array values: %d, %d, %d\n", array_ptr[0], array_ptr[1], array_ptr[2]);
}

int main() {
    TaskflowLib* tf = taskflow_create();
    
    // Create task arguments
    int value = 42;
    float pi = 3.14159f;
    const char* message = "Hello";
    int array[] = {1, 2, 3};
    
    TaskArgs* args = create_task_args(4);
    set_task_arg_ptr(args, 0, &value);
    set_task_arg_ptr(args, 1, &pi);
    set_task_arg_ptr(args, 2, (void*)message);
    set_task_arg_ptr(args, 3, array);
    
    TaskWrapper* task = taskflow_create_task(tf, "multi_arg_task", task_with_multiple_args, args);
    
    taskflow_execute(tf);
    
    // Cleanup
    destroy_task_args(args);
    taskflow_destroy(tf);
    
    return 0;
}