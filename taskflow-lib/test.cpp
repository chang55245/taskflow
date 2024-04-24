#include "lib.hpp"

void test()
{
    printf("A\n");
}
int main(){
    char nameA[] = "A";
    char nameB[] = "B";
    char nameC[] = "C";

    auto myTaskflowLib = taskflowLib();
    auto A = myTaskflowLib.task_definition(nameA, test);
    // auto A = myTaskflowLib.task_definition(nullptr, [](){int c =10+100;});
    auto B = myTaskflowLib.task_definition(nameB, [](){printf("B\n");});
    auto C = myTaskflowLib.task_definition(nameC, [](){printf("C\n");});
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute(); 
}