#include "lib.hpp"


void test()
{


}
int main(){
    auto myTaskflowLib = taskflowLib();
    // auto A = myTaskflowLib.task_definition("A", test);
    // auto A = myTaskflowLib.task_definition(NULL, nullptr);
    // auto A = myTaskflowLib.task_definition("A", [](){printf("A\n");});
    // auto A = myTaskflowLib.task_definition("A", [](){ });
    // void* A;
    void* B;
    void* C;
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute(); 
}