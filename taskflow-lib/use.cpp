#include "lib.hpp"

int main(){
  
    auto myTaskflowLib = taskflowLib();

    auto A = myTaskflowLib.task_definition("A", [](){printf("A\n");});
    auto B = myTaskflowLib.task_definition("B", [](){printf("B\n");});
    auto C = myTaskflowLib.task_definition("C", [](){printf("C\n");});

    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute();    

  return 0;
}