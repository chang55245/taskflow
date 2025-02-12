#include <taskflow/taskflow.hpp>  // Taskflow is header-only

int main(){
  
  tf::Executor executor;
  tf::Taskflow taskflow;

  tf::Task A = taskflow.emplace([](){std::cout << "TaskA\n";}).name("A"); 
  tf::Task B = taskflow.emplace([](){std::cout << "TaskB\n";}).name("B"); 
  tf::Task C = taskflow.emplace([](){std::cout << "TaskC\n";}).name("C"); 
  tf::Task D = taskflow.emplace([](){std::cout << "TaskD\n";}).name("D"); 

                                                                    
  A.precede(B, C);  // A runs before B and C
  D.succeed(B, C);  // D runs after  B and C
                                      
  executor.run(taskflow).wait(); 

  return 0;
}