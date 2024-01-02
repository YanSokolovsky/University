#include "pch.h"
#include "CppUnitTest.h"
#include "..\kolok3\func.h"
#include <vector>
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FuncTesting
{
	TEST_CLASS(DoingTesting)
	{
	public:
		TEST_METHOD(SumTest)
		{
			std::vector<double> a = { 1.2, 1.3, 12.3432, 125.532541 };
			double res = doing(1, a);
			Assert::AreEqual(140.375741, res);
		}
		TEST_METHOD(MultiplyingTest)
		{
			std::vector<double> a = { 1.2, 1.3, 12.3432, 125.532541 };
			double res = doing(2, a);
			double test = 1.2 * 1.3 * 12.3432 * 125.532541;
			Assert::AreEqual(test, res);
		}
		TEST_METHOD(SquareTest)
		{
			std::vector<double> a = { 1.2, 1.3, 12.3432, 125.532541 };
			double res = doing(3, a);
			double test = 1.2 * 1.2 + 1.3 * 1.3 + 12.3432 * 12.3432 + 125.532541 * 125.532541;
			Assert::AreEqual(test, res);
		}
		TEST_METHOD(CrashTest)
		{
			std::vector<double> a = { 1.2, 1.3, 12.3432, 125.532541 };
			double res = doing(10, a);
			Assert::AreEqual(0.0, res);
		}
	};
	TEST_CLASS(ChekTest)
	{
		TEST_METHOD(ExistingOfFilesTest)
		{
			//when you change location of project two tests will brake.
			Assert::IsTrue(chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f3.txt"));
			Assert::IsTrue(chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f2.txt"));
			Assert::IsTrue(chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f1.txt"));
			Assert::IsTrue(!chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f100.txt"));
			Assert::IsTrue(!chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f55.txt"));
		}
		TEST_METHOD(BlockingFilesTest)
		{
			chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f3.txt");
			chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f2.txt");
			chek("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f1.txt");
			std::ofstream f1;
			std::ofstream f2;
			std::ofstream f3;
			f1.open("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f1.txt");
			f2.open("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f2.txt");
			f3.open("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++98\\kolok3\\FuncTesting\\f3.txt");
			Assert::IsTrue(f1.is_open());
			Assert::IsTrue(f2.is_open());
			Assert::IsTrue(f3.is_open());
			f1.close();
			f2.close();
			f3.close();
		}
	};
	TEST_CLASS(StTest)
	{
		TEST_METHOD(ConstructorTest)
		{
			st* sttest = new st();
			Assert::AreEqual(sttest->StartNumber, 0);
			Assert::AreEqual(sttest->JumpNumber, 0);
			Assert::AreEqual(sttest->res, 0.0);
			Assert::AreEqual(0, strcmp(sttest->name.c_str(), "name"));
			Assert::IsFalse(sttest->isoperated);
		}
	};
}
