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

// Original function with direct arguments
void direct_math_task(int x, int y, int* result) {
    *result = x + y;
    printf("Math task: %d + %d = %d\n", x, y, *result);
}

// Wrapper function that unpacks TaskArgs into direct arguments
void math_task_wrapper(TaskArgs* args) {
    int x = *(int*)args->args[0].ptr;
    int y = *(int*)args->args[1].ptr;
    int* result = (int*)args->args[2].ptr;
    direct_math_task(x, y, result);
}

// Original string processing function
void direct_string_task(const char* str1, const char* str2) {
    printf("String task: combining '%s' and '%s'\n", str1, str2);
}

// Wrapper for string processing
void string_task_wrapper(TaskArgs* args) {
    const char* str1 = (const char*)args->args[0].ptr;
    const char* str2 = (const char*)args->args[1].ptr;
    direct_string_task(str1, str2);
}

// Original array processing function
void direct_array_task(int* array, size_t size, int* sum) {
    *sum = 0;
    for(size_t i = 0; i < size; i++) {
        *sum += array[i];
    }
    printf("Array sum: %d\n", *sum);
}

// Wrapper for array processing
void array_task_wrapper(TaskArgs* args) {
    int* array = (int*)args->args[0].ptr;
    size_t size = *(size_t*)args->args[1].ptr;
    int* sum = (int*)args->args[2].ptr;
    direct_array_task(array, size, sum);
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
    
    // Variables for math task
    int x = 10, y = 20, math_result = 0;
    TaskArgs* math_args = create_task_args(3);
    set_task_arg_ptr(math_args, 0, &x);
    set_task_arg_ptr(math_args, 1, &y);
    set_task_arg_ptr(math_args, 2, &math_result);
    
    // Variables for string task
    const char* str1 = "Hello";
    const char* str2 = "World";
    TaskArgs* string_args = create_task_args(2);
    set_task_arg_ptr(string_args, 0, (void*)str1);
    set_task_arg_ptr(string_args, 1, (void*)str2);
    
    // Variables for array task
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    int sum = 0;
    TaskArgs* array_args = create_task_args(3);
    set_task_arg_ptr(array_args, 0, numbers);
    set_task_arg_ptr(array_args, 1, &size);
    set_task_arg_ptr(array_args, 2, &sum);
    
    // Arguments for final task
    TaskArgs* args5 = create_task_args(1);
    set_task_arg_ptr(args5, 0, &sum);
    
    // Create tasks with wrapper functions
    TaskWrapper* task1 = taskflow_create_task(tf, "math_task", math_task_wrapper, math_args);
    TaskWrapper* task2 = taskflow_create_task(tf, "string_task", string_task_wrapper, string_args);
    TaskWrapper* task3 = taskflow_create_task(tf, "array_task", array_task_wrapper, array_args);
    TaskWrapper* task5 = taskflow_create_task(tf, "final_task", final_task, args5);
    
    // Add dependencies
    taskflow_add_dependency(task1, task5);  // math_task -> string_task
    taskflow_add_dependency(task2, task5);  // string_task -> array_task
    taskflow_add_dependency(task3, task5);  // array_task -> final_task
    
    // Execute taskflow
    printf("\nExecuting taskflow...\n");
    printf("-------------------\n");
    taskflow_execute(tf);
    printf("-------------------\n");
    printf("Results:\n");
    printf("Math result: %d\n", math_result);
    printf("Array sum: %d\n", sum);
    printf("-------------------\n");
    
    // Cleanup
    destroy_task_args(args1);
    destroy_task_args(math_args);
    destroy_task_args(string_args);
    destroy_task_args(array_args);
    destroy_task_args(args5);
    taskflow_destroy(tf);
    
    return 0;
}