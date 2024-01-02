#include "pch.h"
#include "CppUnitTest.h"
#include "..\calculating_matrix\func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Matrix
{
	TEST_CLASS(matrixTest)
	{
	public:

		TEST_METHOD(littletest)
		{
			matrix mat(2, 2);
			Assert::AreEqual(mat.mat[0][0], 0);
			Assert::AreEqual(mat.mat[0][1], 0);
			Assert::AreEqual(mat.mat[1][0], 0);
			Assert::AreEqual(mat.mat[1][1], 0);
			Assert::IsFalse(mat.matof[0][0]);
			Assert::IsFalse(mat.matof[0][1]);
			Assert::IsFalse(mat.matof[1][0]);
			Assert::IsFalse(mat.matof[1][1]);
			Assert::IsFalse(mat.done);
			Assert::AreEqual(mat.numberoflines, 2);
			Assert::AreEqual(mat.numberofrows, 2);
		}
		TEST_METHOD(bracestest)
		{
			matrix mat(2, 2);
			mat.mat[0][0] = 1;
			mat.mat[0][1] = 2;
			mat.mat[1][0] = 3;
			mat.mat[1][1] = 4;
			Assert::AreEqual(mat[0][0], 1);
			Assert::AreEqual(mat[0][1], 2);
			Assert::AreEqual(mat[1][0], 3);
			Assert::AreEqual(mat[1][1], 4);
		}
		TEST_METHOD(case1)
		{
			matrix mat1(2, 2);
			mat1.mat[0][0] = 1;
			mat1.mat[0][1] = 0;
			mat1.mat[1][0] = 0;
			mat1.mat[1][1] = 1;
			matrix mat2(2, 2);
			mat2.mat[0][0] = 1;
			mat2.mat[0][1] = 0;
			mat2.mat[1][0] = 0;
			mat2.mat[1][1] = 1;
			matrix res(2, 2);
			calculate(&res, &mat1, &mat2, 0, 0);
			Assert::AreEqual(res[0][0], 1);
			calculate(&res, &mat1, &mat2, 0, 1);
			Assert::AreEqual(res[0][1], 0);
			calculate(&res, &mat1, &mat2, 1, 0);
			Assert::AreEqual(res[1][0], 0);
			calculate(&res, &mat1, &mat2, 1, 1);
			Assert::AreEqual(res[1][1], 1);
		}
	};
}
