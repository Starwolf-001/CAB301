#include <iostream>

using namespace std;

// Sorts a given array by insertion sort
// Input: An array being A with the values [0 ... n - 1] of n orderable elements
// E.G. [0, 2, 6, 9, 7, 1, 10, 54, 8]
// Output: Array A[0 ... n - 1] sorted in nondecreasing order
// E.G. [0, 1, 2, 6, 7, 8, 9, 10, 54]

// variableI stands for i in the InsertionSort Algorithm
int variableI;
// variableV stands for v in the InsertionSort Algorithm
int variableV;
// variableJ stands for j in the InsertionSort Algorithm
int variableJ;
// variable for Length of arrayInput
int sizeValue;
// Array of numbers that are orderable
int arrayInput [3] = {3, 2, 1};

int insertionSort() {
    sizeValue = sizeof(arrayInput)/4;

    for (variableI = 1; variableI < sizeValue; variableI++) {
        variableV = arrayInput[variableI];
        variableJ = variableI - 1;

        while (variableJ >= 0 && arrayInput[variableJ] > variableV) {
            arrayInput[variableJ + 1] = arrayInput[variableJ];
            variableJ = variableJ - 1;
        }
        arrayInput[variableJ + 1] = variableV;
    }
}

int outputArrayToConsole() {
    variableI = 0;
    // Print elements of ArrayInput. Comment out to analysis just Insertion Sort Algorithms
    for (variableI = 0; variableI < sizeValue; variableI++) {
        std::cout << arrayInput[variableI] << "\n";
    }
}

int main() {
    insertionSort();
    outputArrayToConsole();
}
