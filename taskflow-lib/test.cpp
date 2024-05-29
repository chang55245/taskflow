#include "lib.hpp"

void funcA() { 
    int firstMatrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int secondMatrix[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
        int result[3][3];
        int rowFirst = 3, columnFirst = 3, rowSecond = 3, columnSecond = 3;
        for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                result[i][j] = 0;
            }
        }

        // Multiplying firstMatrix and secondMatrix and storing in result.
        for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                for (int k = 0; k < columnFirst; ++k) {
                    result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }
        printf("A\n"); 
}

void funcB() {
        
     printf("B\n"); 
     }

void funcC() { printf("C\n"); }
int main() {
    char nameA[] = "A";
    char nameB[] = "B";
    char nameC[] = "C";

    auto myTaskflowLib = taskflowLib();
    auto A = myTaskflowLib.task_definition(nameA, funcA);
    // auto B = myTaskflowLib.task_definition(nameB, funcB);

    auto B = myTaskflowLib.task_definition(nameB, []() {
        int firstMatrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

       
        int secondMatrix[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
        int result[3][3];
        
        int rowFirst = 3, columnFirst = 3, rowSecond = 3, columnSecond = 3;
        for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                result[i][j] = 0;
            }
        }


        for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                for (int k = 0; k < columnFirst; ++k) {
                    result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }
        printf("B\n");
    });
    auto C = myTaskflowLib.task_definition(nameC, funcC);
    // auto C = myTaskflowLib.task_definition(nameC, [](){printf("C\n");});
    myTaskflowLib.add_dependency(C, B);
    myTaskflowLib.add_dependency(B, A);

    myTaskflowLib.execute();
}