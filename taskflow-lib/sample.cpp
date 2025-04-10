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

void malloc_func(void* ptr, int* test_num){
    printf("test malloc_func\n"); 
    printf("test_num: %d\n", *test_num);
    *(void**)ptr = malloc(sizeof(int)*100);
    *test_num = 100;
    printf("malloc_func after malloc: %p\n", *(void**)ptr);
}

void task_0_wrapper(TaskArgs* args){
    int* args0 = (int*)args->args[0].ptr;
    int* args1  = (int*)args->args[1].ptr;
    task_0(args0, args1);
}

void test_unintialized_pointer(void* ptr, int test_num){
    printf("test_num: %d\n", test_num);

     for (int y1 = 0; y1 < 2; y1++)
    {
      for (int z = 0; z < 2; z++)
      {
        ((int*)ptr)[z] = y1+z;
        printf("y1: %d, z: %d\n",y1, ((int*)ptr)[z]);
      }
    }
}

void task_0_wrapper(TaskArgs* args){
    void* original_ptr = *(void**)args->args[0].ptr;
    int* ptr_to_ptr1 = (int*)args->args[1].ptr;
    printf("original_ptr2222: %p\n", original_ptr);
    test_unintialized_pointer(original_ptr, *ptr_to_ptr1);
    *(void**)args->args[0].ptr = original_ptr;
    *(int*)args->args[1].ptr = *ptr_to_ptr1;
    printf("original_ptr3333: %p\n", original_ptr);
}

void task_0_wrapper(TaskArgs* args){
    int* args0 = (int*)args->args[0].ptr;
    int* args1  = (int*)args->args[1].ptr;
    task_0(args0, args1);
}

void task_1_wrapper(TaskArgs* args){
    int* args0 = (int*)args->args[0].ptr;
    int* args1  = (int*)args->args[1].ptr;
    task_1(args0, args1);
}

int main() {
    TaskflowLib* tf = taskflow_create();
    int task_0_arg0 = 10;
    int task_0_arg1 = 20;
    int task_1_arg0 = 30;
    int task_1_arg1 = 40;
    TaskArgs* task_0_args = create_task_args(2);
    set_task_arg_ptr(task_0_args, 0, &task_0_arg0, sizeof(int));
    set_task_arg_ptr(task_0_args, 1, &task_0_arg1, sizeof(int));
    TaskWrapper* task_0 = taskflow_create_task(tf, "task_0", task_0_wrapper, task_0_args);
    TaskArgs* task_1_args = create_task_args(2);
    set_task_arg_ptr(task_1_args, 0, &task_1_arg0, sizeof(int));
    set_task_arg_ptr(task_1_args, 1, &task_1_arg1, sizeof(int));
    TaskWrapper* task_1 = taskflow_create_task(tf, "task_1", task_1_wrapper, task_1_args);
    taskflow_add_dependency(task_0, task_1);
    taskflow_execute(tf);
    return 0;
}