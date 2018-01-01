#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

// Sorts a given array by insertion sort
// Input: An array being A with the values [0 ... n - 1] of n orderable elements
// E.G. [0, 2, 6, 9, 7, 1, 10, 54, 8]
// Output: Array A[0 ... n - 1] sorted in nondecreasing order
// E.G. [0, 1, 2, 6, 7, 8, 9, 10, 54]

int testNumber = 1;
// Global variable for timer used for analyse the run-time of insertionSort()
double algorithmTimer;
// For while loop in the to stop after a number of tests
int whileCountMain = 0;
// For while loop in InsertionSort
int whileCountInsertionSort = 0;
// variableI stands for i in the InsertionSort Algorithm
int variableI;
// variableV stands for v in the InsertionSort Algorithm
int variableV;
// variableJ stands for j in the InsertionSort Algorithm
int variableJ;
// variable for Length of arrayInput
int sizeValue;
// Array of numbers that are orderable
int arrayInput [100];

int insertRandomNumbers() {
    sizeValue = sizeof(arrayInput)/4;
    for (variableI = 0; variableI < sizeValue; variableI++) {
        variableV = rand();
        arrayInput[variableI] = variableV;
    }
    variableI = 0;
}

int insertionSort() {
    for (variableI = 1; variableI < sizeValue; variableI++) {
        variableV = arrayInput[variableI];
        variableJ = variableI - 1;

        while (variableJ >= 0 && arrayInput[variableJ] > variableV) {
            arrayInput[variableJ + 1] = arrayInput[variableJ];
            variableJ = variableJ - 1;
            whileCountInsertionSort++;
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

int timeInsertionSortFunction() {
    // Timer Initialised
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    // algorithmTimer Start
    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    int startclock = clock();
    // Call function
    insertionSort();
    // algorithmTimer End
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);
    // microseconds algorithmTimer
    double algorithmTimer = static_cast<double>(end.QuadPart- start.QuadPart) / frequency.QuadPart;
    // For time of insertionSort to de displayed on console
    cout << "Elaspsed time is " << algorithmTimer * 1000000.0 << " ms " << endl;
    cout << "The number of Basic Operations performed were " << whileCountInsertionSort << endl;
    whileCountInsertionSort = 0;
}

int programTestsCompleted() {
    cout << "Tests Completed!" << endl;
}

int main() {
    // Intialise a random seed
    srand(time(NULL));
    while(1) {
        cout << "Test " << testNumber << endl;
        cout << "Unsorted Array" << endl;
        testNumber++;
        insertRandomNumbers();
        outputArrayToConsole();
        // The function timeInsertionSortFunction() also calls inerstionSort()
        timeInsertionSortFunction();
        cout << "Sorted Array" << endl;
        outputArrayToConsole();
        // Has 100 tests be performed? If so finished, else continue
        if (whileCountMain == 99) {
            programTestsCompleted();
            return 0;
        } else {
            whileCountMain++;
            whileCountInsertionSort = 0;
        }
    }
}
