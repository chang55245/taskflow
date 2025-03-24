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

void malloc_func1(void* ptr, int* test_num) {
    printf("test number before 1: %d\n", *test_num);
    // int* ptr_to_ptr = (int*)ptr;
    ptr =(int*) malloc(sizeof(int)*100);
    *test_num = 100;
    printf("test number after 1: %d\n", *test_num);
}

void malloc_func2(void* ptr, int* test_num) {
    printf("test number before 2: %d\n", *test_num);
    int* ptr_to_ptr = (int*)ptr;
    ptr_to_ptr[3] = 100;
    *test_num = 200;
    printf("test number after 2: %d\n", *test_num);
}

void malloc_wrapper1(TaskArgs* args) {
    void** private_copy = (void**)args->args[0].private_copy;
    int** test_num = (int**)args->args[1].private_copy;
    // int** org_ptr = (int**)args->args[1].ptr;
    // printf("org ptr address 1: %p\n", org_ptr);
    // printf("org ptr address 1 1: %p\n", *org_ptr);
    // printf("private_copy address 1: %p\n", test_num);
    // printf("private_copy address 1 1: %p\n", *test_num);
    malloc_func1(*private_copy, *test_num);
    taskflow_copy_back(args);
    // printf("copy back 1\n");
}

void malloc_wrapper2(TaskArgs* args) {
    void** private_copy = (void**)args->args[0].private_copy;
    int** test_num = (int**)args->args[1].private_copy;
    // int** org_ptr = (int**)args->args[1].ptr;
    // printf("org ptr address 2: %p\n", org_ptr);
    // printf("org ptr address 2 2: %p\n", *org_ptr);
    // printf("private_copy address 2: %p\n", test_num);
    // printf("private_copy address 2 2: %p\n", *test_num);
    malloc_func2(*private_copy, *test_num);
    taskflow_copy_back(args);
    // printf("copy back 2\n");
}

// void test_unintialized_pointer(void* ptr, int test_num){
//     printf("test_num: %d\n", test_num);

//      for (int y1 = 0; y1 < 2; y1++)
//     {
//       for (int z = 0; z < 2; z++)
//       {
//         ((int*)ptr)[z] = y1+z;
//         printf("y1: %d, z: %d\n",y1, ((int*)ptr)[z]);
//       }
//     }
// }

// void uninitialized_pointer_wrapper(TaskArgs* args){
//     void* original_ptr = *(void**)args->args[0].ptr;
//     int* ptr_to_ptr1 = (int*)args->args[1].ptr;
//     printf("original_ptr2222: %p\n", original_ptr);
//     test_unintialized_pointer(original_ptr, *ptr_to_ptr1);
//     *(void**)args->args[0].ptr = original_ptr;
//     *(int*)args->args[1].ptr = *ptr_to_ptr1;
//     printf("original_ptr3333: %p\n", original_ptr);
// }

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

    void *sum = NULL;
    int test_num = 10;
    int *test_num_ptr = &test_num;
    
    TaskArgs* args5 = create_task_args(2);
    
    // Pass the pointers with correct sizes
    set_task_arg_ptr(args5, 0, &sum, sizeof(void*));
    set_task_arg_ptr(args5, 1, &test_num_ptr, 4);  // Note: sizeof(int*) for pointer
    
    TaskWrapper* task5 = taskflow_create_task(tf, "11", malloc_wrapper1, args5);
    TaskWrapper* task6 = taskflow_create_task(tf, "222", malloc_wrapper2, args5);
    
    taskflow_execute(tf);
    int* sum_ptr = (int*)sum;
    printf("sum: %d\n", sum_ptr[3]);
    printf("test_num: %d\n", test_num);
    
    
    taskflow_destroy(tf);
    return 0;
}