#pragma once
#include <iostream>
#include <string>
using namespace std;

// Function declaration for quicksort algorithm
void quickSort(int* array, int startIndex, int endIndex);

// Function declaration for creating an array from command line arguments
int* createArrayFromArgs(char* args[], int argCount);
