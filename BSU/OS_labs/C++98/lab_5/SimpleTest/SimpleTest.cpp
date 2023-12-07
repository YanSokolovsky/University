#include "pch.h"
#include "CppUnitTest.h"
#include "../Simple/func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SimpleTest
{
	TEST_CLASS(checkPrimeTest)
	{
	public:
		
		TEST_METHOD(nagtiveTest)
		{
			Assert::IsTrue(!checkPrime(-1));
			Assert::IsTrue(!checkPrime(-11));
			Assert::IsTrue(!checkPrime(-12));
			Assert::IsTrue(!checkPrime(-15));
			Assert::IsTrue(!checkPrime(-6));
			Assert::IsTrue(!checkPrime(-62));
			Assert::IsTrue(!checkPrime(-742));
			Assert::IsTrue(!checkPrime(-12321));
			Assert::IsTrue(!checkPrime(-112154235));
			Assert::IsTrue(!checkPrime(-3345));
			Assert::IsTrue(!checkPrime(-44));
			Assert::IsTrue(!checkPrime(-55));
			Assert::IsTrue(!checkPrime(-66));
			Assert::IsTrue(!checkPrime(-77));
			Assert::IsTrue(!checkPrime(-88));
			Assert::IsTrue(!checkPrime(-99));
			Assert::IsTrue(!checkPrime(-100));
		}
		TEST_METHOD(positiveFalseTest)
		{
			Assert::IsTrue(!checkPrime(55));
			Assert::IsTrue(!checkPrime(44));
			Assert::IsTrue(!checkPrime(77));
			Assert::IsTrue(!checkPrime(88));
			Assert::IsTrue(!checkPrime(99));
			Assert::IsTrue(!checkPrime(1000));
			Assert::IsTrue(!checkPrime(12341));
			Assert::IsTrue(!checkPrime(344));
			Assert::IsTrue(!checkPrime(62));
			Assert::IsTrue(!checkPrime(574352));
			Assert::IsTrue(!checkPrime(552452));
			Assert::IsTrue(!checkPrime(5564578));
			Assert::IsTrue(!checkPrime(465472));
			Assert::IsTrue(!checkPrime(4532));
			Assert::IsTrue(!checkPrime(45555));
			Assert::IsTrue(!checkPrime(49));
			Assert::IsTrue(!checkPrime(52135));
			Assert::IsTrue(!checkPrime(5567895));
		}
		TEST_METHOD(positiveTrueTest)
		{
			Assert::IsTrue(checkPrime(2));
			Assert::IsTrue(checkPrime(3));
			Assert::IsTrue(checkPrime(5));
			Assert::IsTrue(checkPrime(7));
			Assert::IsTrue(checkPrime(11));
			Assert::IsTrue(checkPrime(13));
			Assert::IsTrue(checkPrime(17));
			Assert::IsTrue(checkPrime(23));
			Assert::IsTrue(checkPrime(29));
			Assert::IsTrue(checkPrime(31));
			Assert::IsTrue(checkPrime(37));
			Assert::IsTrue(checkPrime(41));
			Assert::IsTrue(checkPrime(47));
			Assert::IsTrue(checkPrime(43));
			Assert::IsTrue(checkPrime(53));
			Assert::IsTrue(checkPrime(59));
			Assert::IsTrue(checkPrime(71));
		}
	};
	TEST_CLASS(GenerateRandomArray)
	{
		TEST_METHOD(isNULL)
		{
			Assert::IsNull(GenerateRandom(0));
			Assert::IsNull(GenerateRandom(-1));
			Assert::IsNull(GenerateRandom(-876));
			Assert::IsNull(GenerateRandom(-43));
			Assert::IsNull(GenerateRandom(-346));
			Assert::IsNull(GenerateRandom(-35));
			Assert::IsNull(GenerateRandom(-4574));
			Assert::IsNull(GenerateRandom(-5674));
			Assert::IsNotNull(GenerateRandom(1));
			Assert::IsNotNull(GenerateRandom(45));
			Assert::IsNotNull(GenerateRandom(876));
			Assert::IsNotNull(GenerateRandom(43));
			Assert::IsNotNull(GenerateRandom(346));
			Assert::IsNotNull(GenerateRandom(35));
			Assert::IsNotNull(GenerateRandom(4574));
			Assert::IsNotNull(GenerateRandom(5674));
		}
		TEST_METHOD(allElementsBiggerThanZero)
		{
			int* array = GenerateRandom(100000);
			for (int i = 0 ; i < 100000; i++)
			{
				Assert::IsTrue(array[i] >= 0);
			}
		}
	};
}
