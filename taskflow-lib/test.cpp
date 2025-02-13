#include <stdio.h>
#include "lib.hpp"

// Task function declarations
void taskA() { printf("Executing Task A\n"); }
void taskB() { printf("Executing Task B\n"); }
void taskC() { printf("Executing Task C\n"); }
void taskD() { printf("Executing Task D\n"); }

int main() {
    TaskflowLib* tf = taskflow_create();
    
    TaskWrapper* A = taskflow_create_task(tf, "A", taskA);
    TaskWrapper* B = taskflow_create_task(tf, "B", taskB);
    TaskWrapper* C = taskflow_create_task(tf, "C", taskC);
    TaskWrapper* D = taskflow_create_task(tf, "D", taskD);
    
    taskflow_add_dependency(A, B);
    taskflow_add_dependency(A, C);
    taskflow_add_dependency(B, D);
    taskflow_add_dependency(C, D);
    
    printf("Number of tasks: %d\n", taskflow_num_tasks(tf));
    printf("Is taskflow empty? %s\n", taskflow_is_empty(tf) ? "yes" : "no");
    
    printf("\nExecuting taskflow...\n");
    printf("-------------------\n");
    
    taskflow_execute(tf);
    
    printf("-------------------\n");
    printf("Execution complete!\n");
    
    taskflow_destroy(tf);
    return 0;
}