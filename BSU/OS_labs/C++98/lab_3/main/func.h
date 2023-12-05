#pragma once
#include <iostream>
#include <windows.h>

// Define a structure to hold the array and related information
struct ArrayInfo
{
    char* array; // The original array
    int size; // The size of the array
    char lowerBound; // The lower bound of the ASCII range
    char upperBound; // The upper bound of the ASCII range
    int product; // The product of the numeric elements in the array
};

// Function to create a new array based on the given conditions
char* CreateNewArray(ArrayInfo* info);

// Function to display the result
void DisplayResult(int delay, char* newArray, ArrayInfo* info);

// Function to multiply the numeric elements in the array
int MultiplyNumericElements(ArrayInfo* info);
