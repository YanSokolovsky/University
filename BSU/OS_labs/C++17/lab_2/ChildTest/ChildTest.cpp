#include "pch.h"
#include "CppUnitTest.h"
#include <time.h> 
#include "../Child/childfunc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChildTest
{
	// Test class for quickSort function
	TEST_CLASS(quickSortTest)
	{
	public:

		// Test case for descending order array
		TEST_METHOD(DescendingOrderArray)
		{
			// Create a descending order array
			int* array = new int[100];
			for (int i = 0; i < 100; i++)
			{
				array[i] = 99 - i;
			}

			// Sort the array
			quickSort(array, 0, 99);

			// Check if the array is sorted in ascending order
			for (int i = 0; i < 99; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
		}

		// Test case for array with identical elements
		TEST_METHOD(IdenticalElementsArray)
		{
			// Create an array with identical elements
			int* array = new int[10];
			for (int i = 0; i < 10; i++)
			{
				array[i] = 234;
			}

			// Sort the array
			quickSort(array, 0, 9);

			// Check if all elements are equal
			for (int i = 0; i < 9; i++)
			{
				Assert::IsTrue(array[i] == array[i + 1]);
			}
		}

		// Test case for array with random elements
		TEST_METHOD(RandomElementsArray)
		{
			// Create an array with random elements
			int* array = new int[10];
			array[0] = 234;
			array[1] = 3;
			array[2] = 456;
			array[3] = 293;
			array[4] = 45;
			array[5] = 23;
			array[6] = 86;
			array[7] = 2;
			array[8] = 21;
			array[9] = 1;

			// Sort the array
			quickSort(array, 0, 9);

			// Check if the array is sorted in ascending order
			for (int i = 0; i < 9; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
		}
	};

	// Test class for createArrayFromArgs function
	TEST_CLASS(MakeMassTest)
	{
		// Test case for checking if the function returns a non-null pointer
		TEST_METHOD(NotNullPointer)
		{
			// Create a char array with one element
			char** mass = new char* [1];
			mass[0] = const_cast<char*>("123");

			// Create an integer array from the char array
			int* a = createArrayFromArgs(mass, 1);

			// Check if the returned pointer is not null
			Assert::IsNotNull(a);
		}

		// Test case for checking if the function correctly converts elements
		TEST_METHOD(CorrectElementConversion)
		{
			// Create a char array with 11 elements
			char** mass = new char* [11];
			mass[0] = const_cast<char*>("asd");
			mass[1] = const_cast<char*>("2");
			mass[2] = const_cast<char*>("3");
			mass[3] = const_cast<char*>("4");
			mass[4] = const_cast<char*>("5");
			mass[5] = const_cast<char*>("6");
			mass[6] = const_cast<char*>("7");
			mass[7] = const_cast<char*>("8");
			mass[8] = const_cast<char*>("9");
			mass[9] = const_cast<char*>("10");
			mass[10] = const_cast<char*>("11");

			// Create an integer array from the char array
			int* a = createArrayFromArgs(mass, 11);

			// Check if the elements are correctly converted
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(a[i], i + 2);
			}
		}
	};
}