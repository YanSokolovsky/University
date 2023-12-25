#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1/func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Define the test suite
namespace UnitTestLab1
{
	// Test class for testing the function that counts numbers divisible by five
	TEST_CLASS(DivisibleByFiveCounterTest)
	{
	public:

		// Test case for a small array
		TEST_METHOD(SmallArrayTest)
		{
			int* array = new int[10]; // Create an array of size 10
			int size = 10; // Size of the array
			for (int i = 0; i < size; i++) // Initialize the array
			{
				array[i] = i;
			}
			ArrayStruct* testStruct = new ArrayStruct(array, size, 0); // Create a test structure
			ProcessArray(testStruct); // Process the array
			Assert::AreEqual(size / 5, testStruct->NumOfDivByFive); // Check the result
		}

		// Test case for a medium-sized array
		TEST_METHOD(MediumArrayTest)
		{
			int* array = new int[10000]; // Create an array of size 10000
			int size = 10000; // Size of the array
			for (int i = 0; i < size; i++) // Initialize the array
			{
				array[i] = i;
			}
			ArrayStruct* testStruct = new ArrayStruct(array, size, 0); // Create a test structure
			ProcessArray(testStruct); // Process the array
			Assert::AreEqual(size / 5, testStruct->NumOfDivByFive); // Check the result
		}

		// Test case for a large array
		TEST_METHOD(LargeArrayTest)
		{
			int* array = new int[100]; // Create an array of size 100
			int size = 100; // Size of the array
			for (int i = 0; i < size; i++) // Initialize the array with multiples of 5
			{
				array[i] = 5 * i;
			}
			ArrayStruct* testStruct = new ArrayStruct(array, size, 0); // Create a test structure
			ProcessArray(testStruct); // Process the array
			Assert::AreEqual(size, testStruct->NumOfDivByFive); // Check the result
		}

		// Test case for an array with variable elements
		TEST_METHOD(VariableArrayTest)
		{
			int* array = new int[10000]; // Create an array of size 10000
			int size = 10000; // Size of the array
			for (int i = 0; i < size; i++) // Initialize the array with variable elements
			{
				int temp = i;
				if (temp % 5 == 0)
				{
					array[i] = temp / 5;
				}
				else
				{
					array[i] = temp;
				}
			}
			ArrayStruct* testStruct = new ArrayStruct(array, size, 0); // Create a test structure
			ProcessArray(testStruct); // Process the array
			Assert::AreEqual(size / 25, testStruct->NumOfDivByFive); // Check the result
		}
	};

	// Test class for testing the array creation function
	TEST_CLASS(ArrayCreationTest)
	{
		// Test case for checking the maximum number of elements in the array
		TEST_METHOD(MaxElementsTest)
		{
			int size = 0; // Size of the array
			int* array; // Pointer to the array
			for (int i = 0; i < 1000; i++) // Repeat the test 1000 times
			{
				array = CreateArray(&size); // Create the array
				Assert::IsTrue(size <= 10); // Check the size of the array
			}
		}

		// Test case for checking that all elements in the array are non-negative
		TEST_METHOD(NonNegativeElementsTest)
		{
			int size = 0; // Size of the array
			int* array; // Pointer to the array
			for (int i = 0; i < 1000; i++) // Repeat the test 1000 times
			{
				array = CreateArray(&size); // Create the array
				for (int j = 0; j < size; j++) // Check each element in the array
				{
					Assert::IsTrue(array[j] >= 0); // Check that the element is non-negative
				}
			}
		}
	};

	// Test class for testing the constructors of the ArrayStruct class
	TEST_CLASS(ArrayStructConstructorTest)
	{
		// Test case for the default constructor
		TEST_METHOD(DefaultConstructorTest)
		{
			ArrayStruct* testStruct = new ArrayStruct(); // Create a test structure using the default constructor
			Assert::IsNull(testStruct->Array); // Check that the array is null
			Assert::AreEqual(0, testStruct->NumOfDivByFive); // Check that the number of elements divisible by five is zero
			Assert::AreEqual(0, testStruct->Size); // Check that the size of the array is zero
		}

		// Test case for the parameterized constructor
		TEST_METHOD(ParameterizedConstructorTest)
		{
			int* array = new int[2]; // Create an array of size 2
			array[0] = 0; // Initialize the first element
			array[1] = 1; // Initialize the second element
			ArrayStruct* testStruct = new ArrayStruct(array, 2, 777); // Create a test structure using the parameterized constructor
			Assert::AreEqual(testStruct->Array[0], array[0]); // Check the first element
			Assert::AreEqual(testStruct->Array[1], array[1]); // Check the second element
			Assert::AreEqual(testStruct->Size, 2); // Check the size of the array
			Assert::AreEqual(testStruct->NumOfDivByFive, 777); // Check the number of elements divisible by five
		}
	};
}