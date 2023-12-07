#include "pch.h"
#include "CppUnitTest.h"
#include "../main/AllThings.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(dataStructTest)
	{
	public:
		
		TEST_METHOD(ConstructorCase1)
		{
			char* array = new char[100];
			for (int i = 0 ; i < 100; i++)
			{
				array[i] = static_cast<char>(i);
			}
			dataStruct* data = new dataStruct(array, 100, 0);
			Assert::AreEqual(data->size, 100);
			for (int i = 0 ; i < data->size; i++)
			{
				Assert::AreEqual(data->array[i], array[i]);
			}
			Assert::AreEqual(data->resultMulti, 0);
			Assert::AreEqual(data->lowerBound, ' ');
			Assert::AreEqual(data->upperBound, ' ');
		}
		TEST_METHOD(ConstructorCase2)
		{
			char* array = new char[1000];
			for (int i = 0; i < 1000; i++)
			{
				array[i] = static_cast<char>(1000 - i);
			}
			dataStruct* data = new dataStruct(array, 1000, 1000);
			Assert::AreEqual(data->size, 1000);
			for (int i = 0; i < data->size; i++)
			{
				Assert::AreEqual(data->array[i], array[i]);
			}
			Assert::AreEqual(data->resultMulti, 1000);
		}
	};
	TEST_CLASS(CreateNewArrayTest)
	{
		TEST_METHOD(AllNumbers)
		{
			char* a = new char[100];
			for (int i = 0; i < 100; i++)
			{
				a[i] = static_cast<char>(i % 10);
			}
			dataStruct* data = new dataStruct(a, 100, 1);
			data->lowerBound = '0';
			data->upperBound = '9';
			char* res = CreateNewArray(data);
			Assert::AreEqual(data->size, 100);
			for (int i = 0 ; i < data->size; i++)
			{
				Assert::AreEqual(data->array[i], a[i]);
			}
		}
		TEST_METHOD(SomeChars)
		{
			char* a = new char[100];
			for (int i = 0; i < 100; i++)
			{
				a[i] = 't';
			}
			char* test = new char[100];
			for (int i = 0 ; i < 100; i++)
			{
				test[i] = '*';
			}
			dataStruct* data = new dataStruct(a, 100, 1);
			data->lowerBound = '0';
			data->upperBound = '9';
			char* res = CreateNewArray(data);
			Assert::AreEqual(data->size, 100);
			for (int i = 0; i < data->size; i++)
			{
				Assert::AreEqual(res[i], test[i]);
			}
		}
		TEST_METHOD(ImpossibleCharecter)
		{
			char* a = new char[100];
			for (int i = 0; i < 100; i++)
			{
				a[i] = static_cast<char>(i % 10);
			}
			char* test = new char[100];
			for (int i = 0; i < 100; i++)
			{
				test[i] = '*';
			}
			dataStruct* data = new dataStruct(a, 100, 1);
			data->lowerBound = '9';
			data->upperBound = '0';
			char* res = CreateNewArray(data);
			Assert::AreEqual(data->size, 100);
			for (int i = 0; i < data->size; i++)
			{
				Assert::AreEqual(res[i], test[i]);
			}
		}
	};
	TEST_CLASS(MultiplyNumericElementsTest)
	{
		TEST_METHOD(withoutZero)
		{
			char* a = new char[100];
			int mult = 1;
			for (int i = 0; i < 100; i++)
			{
				a[i] = static_cast<char>(i % 9 + 1) + '0';
				mult *= i % 9 + 1;
			}
			dataStruct* data = new dataStruct(a, 100, 1);
			data->lowerBound = '0';
			data->upperBound = '9';
			int res = MultiplyNumericElements(data);
			Assert::AreEqual(mult, res);
		}
		TEST_METHOD(witZero)
		{
			char* a = new char[100];
			for (int i = 0; i < 100; i++)
			{
				a[i] = static_cast<char>(i % 10) + '0';
			}
			dataStruct* data = new dataStruct(a, 100, 1);
			data->lowerBound = '0';
			data->upperBound = '9';
			int res = MultiplyNumericElements(data);
			Assert::AreEqual(0, res);
		}
	};
}
