#include "childfunc.h"
#include <cstdlib>

// Function to sort an array using quicksort algorithm
void quickSort(int* array, int startIndex, int endIndex)
{
	int leftIndex = startIndex;
	int rightIndex = endIndex;
	int temp, pivot = array[(startIndex + endIndex + 1) / 2];

	do {
		while (array[leftIndex] < pivot)
			leftIndex++;
		while (array[rightIndex] > pivot)
			rightIndex--;
		if (leftIndex <= rightIndex)
		{
			if (array[leftIndex] > array[rightIndex])
			{
				temp = array[leftIndex];
				array[leftIndex] = array[rightIndex];
				array[rightIndex] = temp;
			}
			rightIndex--;
			leftIndex++;
		}
	} while (leftIndex <= rightIndex);

	if (leftIndex < endIndex)
		quickSort(array, leftIndex, endIndex);
	if (rightIndex > startIndex)
		quickSort(array, startIndex, rightIndex);
};

// Function to create an array from command line arguments
int* createArrayFromArgs(char* args[], int argCount)
{
	int* array = new int[argCount - 1];
	for (int i = 1; i < argCount; i++)
	{
		array[i - 1] = std::atoi(args[i]);
	}
	return array;
};
