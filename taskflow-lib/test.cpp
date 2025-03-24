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

void malloc_func1(void** ptr, int* test_num) {
    printf("test number before 1: %d\n", *test_num);
    *ptr = malloc(sizeof(int) * 100);  // Remove the extra cast
    *test_num = 100;
    printf("test number after 1: %d\n", *test_num);
}

void malloc_func2(void** ptr, int* test_num) {
    printf("test number before 2: %d\n", *test_num);
    printf("ptr value: %p\n", *ptr);
    int* int_ptr = (int*)*ptr;
    if (int_ptr == NULL) {
        printf("Error: int_ptr is NULL\n");
        return;
    }
    printf("About to write to index 3 at address: %p\n", &int_ptr[3]);
    int_ptr[3] = 42;
    *test_num = 200;
    printf("test number after 2: %d\n", *test_num);
}

void malloc_wrapper1(TaskArgs* args) {
    printf("\nWrapper1 entry - examining args:\n");
    printf("  args[0].ptr: %p\n", args->args[0].ptr);
    printf("  args[0].private_copy: %p\n", args->args[0].private_copy);
    printf("  args[1].ptr: %p\n", args->args[1].ptr);
    printf("  args[1].private_copy: %p\n", args->args[1].private_copy);

    void** private_copy = (void**)args->args[0].private_copy;
    int** test_num = (int**)args->args[1].private_copy;
    
    printf("Wrapper1 before func:\n");
    printf("  private_copy addr: %p\n", private_copy);
    printf("  private_copy value: %p\n", *private_copy);
    printf("  test_num addr: %p\n", test_num);
    printf("  test_num ptr value: %p\n", *test_num);
    printf("  test_num value: %d\n", **test_num);
    
    malloc_func1(private_copy, *test_num);
    
    printf("Wrapper1 after func:\n");
    printf("  private_copy addr: %p\n", private_copy);
    printf("  private_copy value: %p\n", *private_copy);
    printf("  test_num addr: %p\n", test_num);
    printf("  test_num ptr value: %p\n", *test_num);
    printf("  test_num value: %d\n", **test_num);
    
    taskflow_copy_back(args);
}

void malloc_wrapper2(TaskArgs* args) {
    printf("\nWrapper2 entry - examining args:\n");
    printf("  args[0].ptr: %p\n", args->args[0].ptr);
    printf("  args[0].private_copy: %p\n", args->args[0].private_copy);
    printf("  args[1].ptr: %p\n", args->args[1].ptr);
    printf("  args[1].private_copy: %p\n", args->args[1].private_copy);

    void** private_copy = (void**)args->args[0].private_copy;
    int** test_num = (int**)args->args[1].private_copy;
    
    printf("Wrapper2 before func:\n");
    printf("  private_copy addr: %p\n", private_copy);
    printf("  private_copy value: %p\n", *private_copy);
    printf("  test_num addr: %p\n", test_num);
    printf("  test_num ptr value: %p\n", *test_num);
    printf("  test_num value: %d\n", **test_num);
    
    malloc_func2(private_copy, *test_num);
    taskflow_copy_back(args);
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
    
    void *sum = NULL;
    int test_num = 10;
    int *test_num_ptr = &test_num;
    
    // Args for first task
    TaskArgs* args5 = create_task_args(2);
    set_task_arg_ptr(args5, 0, &sum, sizeof(int) * 100);
    set_task_arg_ptr(args5, 1, &test_num_ptr, sizeof(int));
    
    // Create first task
    TaskWrapper* task5 = taskflow_create_task(tf, "malloc_task1", malloc_wrapper1, args5);
    
    // Create new args for second task
    TaskArgs* args6 = create_task_args(2);
    set_task_arg_ptr(args6, 0, &sum, sizeof(int) * 100);
    set_task_arg_ptr(args6, 1, &test_num_ptr, sizeof(int));
    
    // Create second task with new args
    TaskWrapper* task6 = taskflow_create_task(tf, "malloc_task2", malloc_wrapper2, args6);
    
    // Add dependency to ensure proper order
    taskflow_add_dependency(task5, task6);
    
    taskflow_execute(tf);
    
    // Check results
    int* int_sum = (int*)sum;
    printf("Value at index 3: %d\n", int_sum[3]);
    printf("test_num: %d\n", test_num);
    
    // Clean up
    free(sum);

    return 0;
}