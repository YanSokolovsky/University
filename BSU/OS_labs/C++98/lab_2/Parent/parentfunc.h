#pragma once
#include <windows.h>
#include <iostream>
#include <string>

// Function to create a command line string from an array of arguments of comand line
std::string createCommandLineString(std::string baseCommand, std::string* argumentsArray, int arraySize);
