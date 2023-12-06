#include "pch.h"
#include "CppUnitTest.h"
#include "../boss/bossfunc.h"
#include <windows.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bossTest
{
	TEST_CLASS(ZeroStartTest)
	{
	public:
		TEST_METHOD(Correct)
		{
			STARTUPINFO si;
			si = ZeroStart();
			Assert::IsTrue(si.cb == sizeof(STARTUPINFO));
		}
	};
}
