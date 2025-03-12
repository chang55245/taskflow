#include <stdio.h>
#include "lib.hpp"

// void task_with_multiple_args(TaskArgs* args) {
//     // Access arguments as pointers
//     int* int_ptr = (int*)args->args[0].ptr;
//     float* float_ptr = (float*)args->args[1].ptr;
//     const char* str_ptr = (const char*)args->args[2].ptr;
//     int* array_ptr = (int*)args->args[3].ptr;
    
//     printf("Int value: %d\n", *int_ptr);
//     printf("Float value: %.2f\n", *float_ptr);
//     printf("String: %s\n", str_ptr);
//     printf("Array values: %d, %d, %d\n", array_ptr[0], array_ptr[1], array_ptr[2]);
// }

// // Original function with direct arguments
// void direct_math_task(int x, int y, int* result) {
//     *result = x + y;
//     printf("Math task: %d + %d = %d\n", x, y, *result);
// }

// // Wrapper function that unpacks TaskArgs into direct arguments
// void math_task_wrapper(TaskArgs* args) {
//     int x = *(int*)args->args[0].ptr;
//     int y = *(int*)args->args[1].ptr;
//     int* result = (int*)args->args[2].ptr;
//     direct_math_task(x, y, result);
// }

// // Original string processing function
// void direct_string_task(const char* str1, const char* str2) {
//     printf("String task: combining '%s' and '%s'\n", str1, str2);
// }

// // Wrapper for string processing
// void string_task_wrapper(TaskArgs* args) {
//     const char* str1 = (const char*)args->args[0].ptr;
//     const char* str2 = (const char*)args->args[1].ptr;
//     direct_string_task(str1, str2);
// }

// // Original array processing function
// void direct_array_task(int* array, size_t size, int* sum) {
//     *sum = 0;
//     for(size_t i = 0; i < size; i++) {
//         *sum += array[i];
//     }
//     printf("Array sum: %d\n", *sum);
// }

// // Wrapper for array processing
// void array_task_wrapper(TaskArgs* args) {
//     int* array = (int*)args->args[0].ptr;
//     size_t size = *(size_t*)args->args[1].ptr;
//     int* sum = (int*)args->args[2].ptr;
//     direct_array_task(array, size, sum);
// }

// void final_task(TaskArgs* args) {
//     int* final_result = (int*)args->args[0].ptr;
//     printf("Final task: result = %d\n", *final_result);
// }

void malloc_func(void* ptr){
    *(void**)ptr = malloc(sizeof(int)*100);
}

void malloc_wrapper(TaskArgs* args){
    void** ptr_to_ptr = (void**)args->args[0].ptr;
    malloc_func(*ptr_to_ptr);
}

void test_unintialized_pointer(void* ptr){

     for (int y1 = 0; y1 < 2; y1++)
    {
      for (int z = 0; z < 2; z++)
      {
        ((int*)ptr)[z] = y1+z;
        printf("y1: %d, z: %d\n",y1, ((int*)ptr)[z]);
      }
    }
}

void uninitialized_pointer_wrapper(TaskArgs* args){
    void** ptr_to_ptr0 = (void**)args->args[0].ptr;
    test_unintialized_pointer(*ptr_to_ptr0);
}

int main() {
    TaskflowLib* tf = taskflow_create();
    
    // // Create task arguments
    // int value = 42;
    // float pi = 3.14159f;
    // const char* message = "Hello";
    // int array[] = {1, 2, 3};
    
    // // Arguments for task 1
    // TaskArgs* args1 = create_task_args(4);
    // set_task_arg_ptr(args1, 0, &value);
    // set_task_arg_ptr(args1, 1, &pi);
    // set_task_arg_ptr(args1, 2, (void*)message);
    // set_task_arg_ptr(args1, 3, array);
    
    // // Variables for math task
    // int x = 10, y = 20, math_result = 0;
    // TaskArgs* math_args = create_task_args(3);
    // set_task_arg_ptr(math_args, 0, &x);
    // set_task_arg_ptr(math_args, 1, &y);
    // set_task_arg_ptr(math_args, 2, &math_result);
    
    // // Variables for string task
    // const char* str1 = "Hello";
    // const char* str2 = "World";
    // TaskArgs* string_args = create_task_args(2);
    // set_task_arg_ptr(string_args, 0, (void*)str1);
    // set_task_arg_ptr(string_args, 1, (void*)str2);
    
    // // Variables for array task
    // int numbers[] = {1, 2, 3, 4, 5};
    // size_t size = 5;
    // int sum = 0;
    // TaskArgs* array_args = create_task_args(3);
    // set_task_arg_ptr(array_args, 0, numbers);
    // set_task_arg_ptr(array_args, 1, &size);
    // set_task_arg_ptr(array_args, 2, &sum);
    
    // // Arguments for final task
    // TaskArgs* args5 = create_task_args(1);
    // set_task_arg_ptr(args5, 0, &sum);

    // int* sum_original = (int*)malloc(sizeof(int)*100);
    // TaskArgs* args4 = create_task_args(1);

    // void* sum_original_ptr = &sum_original;

    // set_task_arg_ptr(args4, 0, sum_original_ptr);
    // TaskWrapper* task4 = taskflow_create_task(tf, "uninitialized_pointer_wrapper1", uninitialized_pointer_wrapper, args4);
    

    // void *sum_original;
    // malloc_func(&sum_original);
    // test_unintialized_pointer(sum_original);

    // printf("sum_original: %p\n", sum_original);

    void *sum;
    TaskArgs* args5 = create_task_args(1);

    void *sum2 = &sum;
    void **sum3 = &sum2;
    set_task_arg_ptr(args5, 0, sum3);

    TaskWrapper* task5 = taskflow_create_task(tf, "malloc", malloc_wrapper, args5);
    

    TaskArgs* args6 = create_task_args(1);
    set_task_arg_ptr(args6, 0, &sum);

    TaskWrapper* task6 = taskflow_create_task(tf, "uninitialized_pointer_wrapper", uninitialized_pointer_wrapper, args6);
    
    
    // taskflow_add_dependency(task4, task5);
    taskflow_add_dependency(task5, task6);

    // // Create tasks with wrapper functions
    // TaskWrapper* task1 = taskflow_create_task(tf, "math_task", math_task_wrapper, math_args);
    // TaskWrapper* task2 = taskflow_create_task(tf, "string_task", string_task_wrapper, string_args);
    // TaskWrapper* task3 = taskflow_create_task(tf, "array_task", array_task_wrapper, array_args);
    // TaskWrapper* task5 = taskflow_create_task(tf, "final_task", final_task, args5);
    
    // Add dependencies
    // taskflow_add_dependency(task1, task5);  // math_task -> string_task
    // taskflow_add_dependency(task2, task5);  // string_task -> array_task
    // taskflow_add_dependency(task3, task5);  // array_task -> final_task
    
    // Execute taskflow
    // printf("\nExecuting taskflow...\n");
    // printf("-------------------\n");
    taskflow_execute(tf);
    // printf("-------------------\n");
    // printf("Results:\n");
    // printf("Math result: %d\n", math_result);
    // printf("Array sum: %d\n", sum);
    // printf("-------------------\n");
    
    // // Cleanup
    // destroy_task_args(args1);
    // destroy_task_args(math_args);
    // destroy_task_args(string_args);
    // destroy_task_args(array_args);
    // destroy_task_args(args5);
    taskflow_destroy(tf);
    
    return 0;
}