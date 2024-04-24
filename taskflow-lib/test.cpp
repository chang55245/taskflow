#include "lib.hpp"

void funcA()
{
    printf("A\n");
}

void funcB()
{
    printf("B\n");
}

void funcC()
{
    printf("C\n");
}
int main(){
    char nameA[] = "A";
    char nameB[] = "B";
    char nameC[] = "C";

    auto myTaskflowLib = taskflowLib();
    auto A = myTaskflowLib.task_definition(nameA, funcA);
    auto B = myTaskflowLib.task_definition(nameB, funcB);
    auto C = myTaskflowLib.task_definition(nameC, funcC);
    // auto B = myTaskflowLib.task_definition(nameB, [](){printf("B\n");});
    // auto C = myTaskflowLib.task_definition(nameC, [](){printf("C\n");});
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute(); 
}