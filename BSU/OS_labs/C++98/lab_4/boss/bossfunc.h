#pragma once
#include <string>
#include <windows.h>
STARTUPINFO ZeroStart();
char* MakeComLine(std::string exename, int param);