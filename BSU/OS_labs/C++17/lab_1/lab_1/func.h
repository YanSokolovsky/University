#pragma once
#include <iostream>
#include <time.h>

// Define a structure for the array
struct ArrayStruct {
	int* Array; // Pointer to the array
	int Size; // Size of the array
	int NumOfDivByFive; // Number of elements divides by five in the array
	ArrayStruct(); // Default constructor
	ArrayStruct(int* array, int size, int numOfFives);
};

// Function to process the array
void ProcessArray(ArrayStruct* arr);

// Function to create the array
int* CreateArray(int* size);