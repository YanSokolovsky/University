#include "pch.h"
#include "CppUnitTest.h"
#include "../main/func.h"
#include <time.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(MakingNewArrayTest)
	{
	public:
		
		TEST_METHOD(OnlyDigits)
		{
			srand(time(0));
			char* arr = new char[100];
			for (int i = 0 ; i < 100; i++) 
			{
				arr[i] = static_cast<char>(rand() % 10 + static_cast<int>('0'));
			}
			char* newar;
			ArrayInfo a;
			a.upperBound = '0';
			a.lowerBound = '9';
			a.size = 100;
			a.product = 0;
			a.array = arr;
			newar = CreateNewArray(&a);
			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(newar[i], arr[i]);
			}
		}
		TEST_METHOD(SomeChars)
		{
			srand(time(0));
			char* arr = new char[100];
			char* newar;
			ArrayInfo a;
			a.upperBound = '0';
			a.lowerBound = '9';
			a.size = 100;
			a.product = 0;
			int iter = 0;
			for (int i = 0; i < 100; i++)
			{
				int t = rand();
				if (t - static_cast<int>(a.upperBound) >= 0 && t - static_cast<int>(a.lowerBound) <= 0)
				{
					arr[iter] = static_cast<char>(t);
					iter++;
				}
			}
			for (int i = iter; i < 100; i++)
			{
				arr[i] = '*';
			}
			a.array = arr;
			newar = CreateNewArray(&a);
			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(newar[i], arr[i]);
			}
		}
	};
	TEST_CLASS(MultiplyingElementsTest)
	{
		TEST_METHOD(Multiply) {
			srand(time(0));
			char* arr = new char[100];
			int res = 1;
			for (int i = 0; i < 100; i++)
			{
				arr[i] = static_cast<char>(rand() % 10 + static_cast<int>('0'));
				res *= arr[i];
			}
			ArrayInfo a;
			a.upperBound = '0';
			a.lowerBound = '9';
			a.size = 100;
			a.product = 0;
			a.array = arr;
			a.product = MultiplyNumericElements(&a);
			Assert::AreEqual(a.product, res);
		}
	};
}
