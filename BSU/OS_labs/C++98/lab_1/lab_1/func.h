#pragma once
#include <iostream>
#include <time.h>
using namespace std;
struct mymass {
	int* Mass;
	int Count;
	int NumberOf5;
	mymass();
	mymass(int* array, int count, int numberof5);
};
void FuncWroker(mymass* my);
int* FuncMakeMass(int* count);