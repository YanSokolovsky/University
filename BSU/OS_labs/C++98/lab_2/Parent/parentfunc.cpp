#include "parentfunc.h"
string MakeComandLine(string a, string* arr, int sizeOfArray)
{
    string strForComandLine = a;
    for (int i = 0; i < sizeOfArray; i++)
    {
        strForComandLine.append(" ");
        strForComandLine.append(arr[i]);
    }
    return strForComandLine;
};