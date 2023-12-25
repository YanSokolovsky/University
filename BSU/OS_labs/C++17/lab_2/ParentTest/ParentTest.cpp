#include "pch.h"
#include "CppUnitTest.h"
#include "../Parent/parentfunc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParentTest
{
	TEST_CLASS(CreateCommandLineStringTest)
	{
	public:

		// Test case with one parameter
		TEST_METHOD(WithOneParameter)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[1];
			parameters[0] = "123";
			command = createCommandLineString(command, parameters, 1);
			Assert::AreEqual(0, strcmp("asd 123", command.c_str()));
		}

		// Test case with two parameters
		TEST_METHOD(WithTwoParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[2];
			parameters[0] = "123";
			parameters[1] = "123";
			command = createCommandLineString(command, parameters, 2);
			Assert::AreEqual(0, strcmp("asd 123 123", command.c_str()));
		}

		// Test case with three parameters
		TEST_METHOD(WithThreeParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[3];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			command = createCommandLineString(command, parameters, 3);
			Assert::AreEqual(0, strcmp("asd 123 123 123", command.c_str()));
		}

		// Test case with four parameters
		TEST_METHOD(WithFourParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[4];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			command = createCommandLineString(command, parameters, 4);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123", command.c_str()));
		}

		// Test case with five parameters
		TEST_METHOD(WithFiveParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[5];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			parameters[4] = "123";
			command = createCommandLineString(command, parameters, 5);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123", command.c_str()));
		}

		// Test case with six parameters
		TEST_METHOD(WithSixParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[6];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			parameters[4] = "123";
			parameters[5] = "123";
			command = createCommandLineString(command, parameters, 6);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123", command.c_str()));
		}

		// Test case with seven parameters
		TEST_METHOD(WithSevenParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[7];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			parameters[4] = "123";
			parameters[5] = "123";
			parameters[6] = "123";
			command = createCommandLineString(command, parameters, 7);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123", command.c_str()));
		}

		// Test case with eight parameters
		TEST_METHOD(WithEightParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[8];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			parameters[4] = "123";
			parameters[5] = "123";
			parameters[6] = "123";
			parameters[7] = "123";
			command = createCommandLineString(command, parameters, 8);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123 123", command.c_str()));
		}

		// Test case with nine parameters
		TEST_METHOD(WithNineParameters)
		{
			std::string command = "asd";
			std::string* parameters = new std::string[9];
			parameters[0] = "123";
			parameters[1] = "123";
			parameters[2] = "123";
			parameters[3] = "123";
			parameters[4] = "123";
			parameters[5] = "123";
			parameters[6] = "123";
			parameters[7] = "123";
			parameters[8] = "123";
			command = createCommandLineString(command, parameters, 9);
			Assert::AreEqual(0, strcmp("asd 123 123 123 123 123 123 123 123 123", command.c_str()));
		}
	};
}