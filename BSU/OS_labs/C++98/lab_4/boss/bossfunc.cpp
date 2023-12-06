#include "bossfunc.h"
char* MakeComLine(std::string exename, int param)
{
	exename = exename + " " + std::to_string(param);
	char buf[255];
	strcpy_s(buf, exename.c_str());
	return buf;
}
STARTUPINFO ZeroStart()
{
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	return si;
}