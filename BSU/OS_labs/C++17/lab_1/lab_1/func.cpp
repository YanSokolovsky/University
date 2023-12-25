#include "func.h"

// Default constructor
ArrayStruct::ArrayStruct()
{
	Array = NULL; // Initialize the array pointer to NULL
	Size = 0; // Initialize the size to 0
	NumOfDivByFive = 0; // Initialize the number of elements divisible by five to 0
};

// Parameterized constructor
ArrayStruct::ArrayStruct(int* array, int size, int divByFive)
{
	Array = array; // Set the array pointer
	Size = size; // Set the size
	NumOfDivByFive = divByFive; // Set the number of elements divisible by five
};

// Function to process the array
void ProcessArray(ArrayStruct* my)
{
	my->NumOfDivByFive = 0; // Reset the number of elements divisible by five

	// Iterate over the array
	for (int i = 0; i < my->Size; i++)
	{
		// If the current element is divisible by five, increment the count

		if (my->Array[i] % 5 == 0)
			my->NumOfDivByFive++;
	}

	return; // Return from the function
};

// Function to create the array
int* CreateArray(int* count)
{
	srand(time(NULL)); // Seed the random number generator
	*count = rand() % 10 + 1; // Generate a random size for the array
	int* mass = new int[*count]; // Allocate memory for the array

	// Fill the array with random numbers and print them
	for (int i = 0; i < *count; i++)
	{
		mass[i] = rand() % 100;
		std::cout << mass[i] << " ";
	}

	return mass; // Return the array
};