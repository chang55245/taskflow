#include <iostream>
#include "lib.hpp"

// Task function declarations
void taskA() { std::cout << "Executing Task A\n"; }
void taskB() { std::cout << "Executing Task B\n"; }
void taskC() { std::cout << "Executing Task C\n"; }
void taskD() { std::cout << "Executing Task D\n"; }

int main() {
    // Create taskflow library instance
    taskflowLib tf;
    
    // Create tasks
    void* A = tf.task_definition("A", taskA);
    void* B = tf.task_definition("B", taskB);
    void* C = tf.task_definition("C", taskC);
    void* D = tf.task_definition("D", taskD);
    
    // Add dependencies
    // A -> B -> D
    //   -> C ->
    tf.add_dependency(A, B);  // A runs before B
    tf.add_dependency(A, C);  // A runs before C
    tf.add_dependency(B, D);  // B runs before D
    tf.add_dependency(C, D);  // C runs before D
    
    // Print task information
    std::cout << "Number of tasks: " << tf.num_tasks() << "\n";
    std::cout << "Is taskflow empty? " << (tf.is_empty() ? "yes" : "no") << "\n";
    
    std::cout << "\nExecuting taskflow...\n";
    std::cout << "-------------------\n";
    
    // Execute the taskflow
    tf.execute();
    
    std::cout << "-------------------\n";
    std::cout << "Execution complete!\n";
    
    return 0;
}