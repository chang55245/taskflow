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

void math_task(TaskArgs* args) {
    int* x = (int*)args->args[0].ptr;
    int* y = (int*)args->args[1].ptr;
    int* result = (int*)args->args[2].ptr;
    
    *result = *x + *y;
    printf("Math task: %d + %d = %d\n", *x, *y, *result);
}

void string_processing_task(TaskArgs* args) {
    const char* str1 = (const char*)args->args[0].ptr;
    const char* str2 = (const char*)args->args[1].ptr;
    printf("String processing task: combining '%s' and '%s'\n", str1, str2);
}

void array_sum_task(TaskArgs* args) {
    int* array = (int*)args->args[0].ptr;
    size_t* size = (size_t*)args->args[1].ptr;
    int* sum = (int*)args->args[2].ptr;
    
    *sum = 0;
    for(size_t i = 0; i < *size; i++) {
        *sum += array[i];
    }
    printf("Array sum task: sum = %d\n", *sum);
}

void final_task(TaskArgs* args) {
    int* final_result = (int*)args->args[0].ptr;
    printf("Final task: result = %d\n", *final_result);
}

int main() {
    TaskflowLib* tf = taskflow_create();
    
    // Create task arguments
    int value = 42;
    float pi = 3.14159f;
    const char* message = "Hello";
    int array[] = {1, 2, 3};
    
    // Arguments for task 1
    TaskArgs* args1 = create_task_args(4);
    set_task_arg_ptr(args1, 0, &value);
    set_task_arg_ptr(args1, 1, &pi);
    set_task_arg_ptr(args1, 2, (void*)message);
    set_task_arg_ptr(args1, 3, array);
    
    // Arguments for math task
    int x = 10, y = 20, math_result = 0;
    TaskArgs* args2 = create_task_args(3);
    set_task_arg_ptr(args2, 0, &x);
    set_task_arg_ptr(args2, 1, &y);
    set_task_arg_ptr(args2, 2, &math_result);
    
    // Arguments for string task
    const char* str1 = "First";
    const char* str2 = "Second";
    TaskArgs* args3 = create_task_args(2);
    set_task_arg_ptr(args3, 0, (void*)str1);
    set_task_arg_ptr(args3, 1, (void*)str2);
    
    // Arguments for array sum task
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    int sum = 0;
    TaskArgs* args4 = create_task_args(3);
    set_task_arg_ptr(args4, 0, numbers);
    set_task_arg_ptr(args4, 1, &size);
    set_task_arg_ptr(args4, 2, &sum);
    
    // Arguments for final task
    TaskArgs* args5 = create_task_args(1);
    set_task_arg_ptr(args5, 0, &sum);
    
    // Create tasks
    TaskWrapper* task1 = taskflow_create_task(tf, "multi_arg_task", task_with_multiple_args, args1);
    TaskWrapper* task2 = taskflow_create_task(tf, "math_task", math_task, args2);
    TaskWrapper* task3 = taskflow_create_task(tf, "string_task", string_processing_task, args3);
    TaskWrapper* task4 = taskflow_create_task(tf, "array_sum_task", array_sum_task, args4);
    TaskWrapper* task5 = taskflow_create_task(tf, "final_task", final_task, args5);
    
    // Add dependencies
    taskflow_add_dependency(task1, task2);  // task1 -> task2
    taskflow_add_dependency(task1, task3);  // task1 -> task3
    taskflow_add_dependency(task2, task4);  // task2 -> task4
    taskflow_add_dependency(task3, task4);  // task3 -> task4
    taskflow_add_dependency(task4, task5);  // task4 -> task5
    
    // Execute taskflow
    printf("\nExecuting taskflow...\n");
    printf("-------------------\n");
    taskflow_execute(tf);
    printf("-------------------\n");
    printf("Execution complete!\n\n");
    
    // Cleanup
    destroy_task_args(args1);
    destroy_task_args(args2);
    destroy_task_args(args3);
    destroy_task_args(args4);
    destroy_task_args(args5);
    taskflow_destroy(tf);
    
    return 0;
}