#include "bossfunc.h"
std::string MakeComLine(std::string exename, int param)
{
	exename = exename + " " + std::to_string(param);
	return exename;
}