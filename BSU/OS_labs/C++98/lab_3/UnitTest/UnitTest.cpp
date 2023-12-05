#include "pch.h" // Precompiled header file for Visual Studio
#include "CppUnitTest.h" // Header file for CppUnitTest framework
#include "../main/func.h" // Header file for the functions to be tested
#include <time.h> // Header file for time-related functions
using namespace Microsoft::VisualStudio::CppUnitTestFramework; // Using namespace for CppUnitTest framework

namespace UnitTest // Namespace for unit tests
{
	TEST_CLASS(MakingNewArrayTest) // Test class for making a new array
	{
	public:

		TEST_METHOD(OnlyDigits) // Test method for arrays containing only digits
		{
			srand(time(0)); // Seed the random number generator
			char* arr = new char[100]; // Create a new character array
			for (int i = 0; i < 100; i++) // Fill the array with random digits
			{
				arr[i] = static_cast<char>(rand() % 10 + static_cast<int>('0'));
			}
			char* newar; // Pointer for the new array
			ArrayInfo a; // Array information structure
			a.upperBound = '0'; // Upper bound for the array elements
			a.lowerBound = '9'; // Lower bound for the array elements
			a.size = 100; // Size of the array
			a.product = 0; // Product of the array elements
			a.array = arr; // Pointer to the array
			newar = CreateNewArray(&a); // Create a new array
			for (int i = 0; i < 100; i++) // Check if the new array is equal to the original array
			{
				Assert::AreEqual(newar[i], arr[i]);
			}
		}
		TEST_METHOD(SomeChars) // Test method for arrays containing some characters
		{
			srand(time(0)); // Seed the random number generator
			char* arr = new char[100]; // Create a new character array
			char* newar; // Pointer for the new array
			ArrayInfo a; // Array information structure
			a.upperBound = '0'; // Upper bound for the array elements
			a.lowerBound = '9'; // Lower bound for the array elements
			a.size = 100; // Size of the array
			a.product = 0; // Product of the array elements
			int iter = 0; // Iterator for the array
			for (int i = 0; i < 100; i++) // Fill the array with random characters
			{
				int t = rand();
				if (t - static_cast<int>(a.upperBound) >= 0 && t - static_cast<int>(a.lowerBound) <= 0)
				{
					arr[iter] = static_cast<char>(t);
					iter++;
				}
			}
			for (int i = iter; i < 100; i++) // Fill the rest of the array with '*'
			{
				arr[i] = '*';
			}
			a.array = arr; // Pointer to the array
			newar = CreateNewArray(&a); // Create a new array
			for (int i = 0; i < 100; i++) // Check if the new array is equal to the original array
			{
				Assert::AreEqual(newar[i], arr[i]);
			}
		}
	};
	TEST_CLASS(MultiplyingElementsTest) // Test class for multiplying elements
	{
		TEST_METHOD(Multiply) { // Test method for multiplying elements
			srand(time(0)); // Seed the random number generator
			char* arr = new char[100]; // Create a new character array
			int res = 1; // Result of the multiplication
			for (int i = 0; i < 100; i++) // Fill the array with random digits and calculate the product
			{
				arr[i] = static_cast<char>(rand() % 10 + static_cast<int>('0'));
				res *= arr[i];
			}
			ArrayInfo a; // Array information structure
			a.upperBound = '0'; // Upper bound for the array elements
			a.lowerBound = '9'; // Lower bound for the array elements
			a.size = 100; // Size of the array
			a.product = 0; // Product of the array elements
			a.array = arr; // Pointer to the array
			a.product = MultiplyNumericElements(&a); // Calculate the product of the numeric elements
			Assert::AreEqual(a.product, res); // Check if the calculated product is equal to the expected product
		}
	};
}
