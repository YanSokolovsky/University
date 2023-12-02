#include "pch.h"
#include "CppUnitTest.h"
#include "../Parent/parentfunc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParentTest
{
	TEST_CLASS(MakeComandLineTest)
	{
	public:
		
		TEST_METHOD(With1Parametr)
		{
			string a = "asd";
			string* arr = new string[1];
			arr[0] = "123";
			a = MakeComandLine(a, arr, 1);
			Assert::AreEqual(0, strcmp("asd 123", a.c_str()));
		}
		TEST_METHOD(With2Parametr)
		{
			string a = "asd";
			string* arr = new string[2];
			arr[0] = "123";
			arr[1] = "123";
			a = MakeComandLine(a, arr, 2);
			Assert::AreEqual(0, strcmp("asd 123 123", a.c_str()));
		}
		TEST_METHOD(With3Parametr)
		{
			string a = "asd";
			string* arr = new string[3];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			a = MakeComandLine(a, arr, 3);
			Assert::AreEqual(0, strcmp("asd 123 123 123", a.c_str()));
		}
		TEST_METHOD(With4Parametr)
		{
			string a = "asd";
			string* arr = new string[4];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			a = MakeComandLine(a, arr, 4);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123", a.c_str()));
		}
		TEST_METHOD(With5Parametr)
		{
			string a = "asd";
			string* arr = new string[5];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			arr[4] = "123";
			a = MakeComandLine(a, arr, 5);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123", a.c_str()));
		}
		TEST_METHOD(With6Parametr)
		{
			string a = "asd";
			string* arr = new string[6];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			arr[4] = "123";
			arr[5] = "123";
			a = MakeComandLine(a, arr, 6);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123", a.c_str()));
		}
		TEST_METHOD(With7Parametr)
		{
			string a = "asd";
			string* arr = new string[7];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			arr[4] = "123";
			arr[5] = "123";
			arr[6] = "123";
			a = MakeComandLine(a, arr, 7);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123", a.c_str()));
		}
		TEST_METHOD(With8Parametr)
		{
			string a = "asd";
			string* arr = new string[8];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			arr[4] = "123";
			arr[5] = "123";
			arr[6] = "123";
			arr[7] = "123";
			a = MakeComandLine(a, arr, 8);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123 123", a.c_str()));
		}
		TEST_METHOD(With9Parametr)
		{
			string a = "asd";
			string* arr = new string[9];
			arr[0] = "123";
			arr[1] = "123";
			arr[2] = "123";
			arr[3] = "123";
			arr[4] = "123";
			arr[5] = "123";
			arr[6] = "123";
			arr[7] = "123";
			arr[8] = "123";
			a = MakeComandLine(a, arr, 9);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123 123 123", a.c_str()));
		}
	};
}
