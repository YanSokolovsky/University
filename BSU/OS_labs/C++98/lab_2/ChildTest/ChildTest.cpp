#include "pch.h"
#include "CppUnitTest.h"
#include <time.h> 
#include "../childfunc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChildTest
{
	TEST_CLASS(sortTest)
	{
	public:
		
		TEST_METHOD(Case1)
		{
			int* array = new int[100];
			for (int i = 0 ; i < 100; i++)
			{
				array[i] = 99 - i;
			}
			sort(array, 0, 99);
			for (int i = 0; i < 99; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
		}
		TEST_METHOD(Case2)
		{
			int* array = new int[10];
			array[0] = 234;
			array[1] = 234;
			array[2] = 234;
			array[3] = 234;
			array[4] = 234;
			array[5] = 234;
			array[6] = 234;
			array[7] = 234;
			array[8] = 234;
			array[9] = 234;
			sort(array, 0, 9);
			for (int i = 0; i < 9; i++)
			{
				Assert::IsTrue(array[i] == array[i + 1]);
			}
		}
		TEST_METHOD(Case3)
		{
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
			sort(array, 0, 9);
			for (int i = 0; i < 9; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
		}
	};
	TEST_CLASS(MakeMassTest)
	{
		TEST_METHOD(IsNUll)
		{
			char** mass = new char* [1];
			mass[0] = "123";
			int* a = MakeMass(mass, 1);
			Assert::IsNotNull(a);
		}
		TEST_METHOD(AccordingToElements)
		{
			char** mass = new char* [11];
			mass[0] = "asd";
			mass[1] = "2";
			mass[2] = "3";
			mass[3] = "4";
			mass[4] = "5";
			mass[5] = "6";
			mass[6] = "7";
			mass[7] = "8";
			mass[8] = "9";
			mass[9] = "10";
			mass[10] = "11";
			int* a = MakeMass(mass, 11);
			Assert::AreEqual(a[0], 2);
			Assert::AreEqual(a[1], 3);
			Assert::AreEqual(a[2], 4);
			Assert::AreEqual(a[3], 5);
			Assert::AreEqual(a[4], 6);
			Assert::AreEqual(a[5], 7);
			Assert::AreEqual(a[6], 8);
			Assert::AreEqual(a[7], 9);
			Assert::AreEqual(a[8], 10);
			Assert::AreEqual(a[9], 11);
		}
	};
}
