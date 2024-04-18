#include "lib.hpp"

int main(){
    auto myTaskflowLib = taskflowLib();
    // void* A;
    void* A;
    void* B;
    void* C;
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute(); 
}