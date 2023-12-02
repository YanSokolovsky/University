#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1/func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1
{
	TEST_CLASS(FuncWorkerTest)
	{
	public:

		TEST_METHOD(countingTest1)
		{
			int* mass = new int[10];
			int count = 10;
			for (int i = 0; i < 10; i++)
			{
				mass[i] = i;
			}
			mymass* test = new mymass(mass, count, 0);
			FuncWroker(test);
			Assert::AreEqual(count / 5, test->NumberOf5);
		}
		TEST_METHOD(countingTest2)
		{
			int* mass = new int[10000];
			int count = 10000;
			for (int i = 0; i < 10000; i++)
			{
				mass[i] = i;
			}
			mymass* test = new mymass(mass, count, 0);
			FuncWroker(test);
			Assert::AreEqual(count / 5, test->NumberOf5);
		}
		TEST_METHOD(countingTest3)
		{
			int* mass = new int[100];
			int count = 100;
			for (int i = 0; i < 100; i++)
			{
				mass[i] = 5 * i;
			}
			mymass* test = new mymass(mass, count, 0);
			FuncWroker(test);
			Assert::AreEqual(count, test->NumberOf5);
		}
		TEST_METHOD(countingTest4)
		{
			int* mass = new int[10000];
			int count = 10000;
			for (int i = 0; i < 10000; i++)
			{
				int a = i;
				if (a % 5 == 0)
				{
					mass[i] = a / 5;
				}
				else
				{
					mass[i] = a;
				}
			}
			mymass* test = new mymass(mass, count, 0);
			FuncWroker(test);
			Assert::AreEqual(count / 25, test->NumberOf5);
		}
	};
	TEST_CLASS(FuncMakeMassTest)
	{
		TEST_METHOD(NumberOfElementsLessThanTen)
		{
			int count = 0;
			int* mass;
			for (int i = 0 ; i < 1000; i++)
			{
				mass = FuncMakeMass(&count);
				Assert::IsTrue(count <= 10);
			}
		}
		TEST_METHOD(ElementsLessThanHundred)
		{
			int count = 0;
			int* mass;
			for (int i = 0; i < 1000; i++)
			{
				mass = FuncMakeMass(&count);
				for (int g = 0; g < count; g++)
				{
					Assert::IsTrue(mass[g] >= 0);
				}
			}
		}
		TEST_METHOD(ElementsBiggerThanZero)
		{
			int count = 0;
			int* mass;
			for (int i = 0; i < 1000; i++)
			{
				mass = FuncMakeMass(&count);
				for (int g = 0; g < count; g++)
				{
					Assert::IsTrue(mass[g] >= 0);
				}
			}
		}
	};
	TEST_CLASS(mymassConstructorsTest)
	{
		TEST_METHOD(WithoutParametrs)
		{
			mymass* t = new mymass();
			Assert::IsNull(t->Mass);
			Assert::AreEqual(0, t->NumberOf5);
			Assert::AreEqual(0, t->Count);
		}
		TEST_METHOD(WtihParametrs)
		{
			int* mass = new int[2];
			mass[0] = 0;
			mass[1] = 1;
			mymass* t = new mymass(mass, 2, 777);
			Assert::AreEqual(t->Mass[0], mass[0]);
			Assert::AreEqual(t->Mass[1], mass[1]);
			Assert::AreEqual(t->Count, 2);
			Assert::AreEqual(t->NumberOf5, 777);
		}
	};
}
