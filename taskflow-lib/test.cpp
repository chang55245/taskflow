#include "lib.hpp"


void test()
{


}
int main(){
    auto myTaskflowLib = taskflowLib();
    // void* A;
    // void* A;
    auto A = myTaskflowLib.task_definition("A", test);
    void* B;
    void* C;
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute(); 
}