#include <windows.h>
#include <iostream>
#include <time.h>
#include "func.h"
using namespace std;

DWORD WINAPI worker(LPVOID n)
{
	mymass* my = (mymass*)n;
	FuncWroker(my);
	return 0;
}
DWORD WINAPI mainThreadFunc(LPVOID n)
{
	mymass *my1;
	int a; // number of numbers in array.
	int* mass = FuncMakeMass(&a); // array with "a" elements. In this method a get it`s value.
	cout << endl;
	my1 = new mymass(mass, a, 0);
	DWORD IDThread;
	HANDLE thread1;
	thread1 = CreateThread(NULL, 0, worker, (void*)my1, 0, &IDThread);
	if (thread1 == 0)
		return 0;
	SuspendThread(thread1);
	cout << "the main  thread is sleeping." << endl;
	Sleep(1000);
	cout << "the main thread woke up." << endl;
	ResumeThread(thread1);
	WaitForSingleObject(thread1, INFINITE);
	cout << my1->NumberOf5;
	if (thread1 == 0)
		return 0;
	CloseHandle(thread1);
	return 0;
}
int main()
{
	DWORD IDThread;
	HANDLE thread;
	int trash = 0;
	thread = CreateThread(NULL, 0, mainThreadFunc, (void*)trash, 0, &IDThread);
	if (thread == NULL)
		return GetLastError();
	WaitForSingleObject(thread, INFINITE);
	CloseHandle(thread);
	return 0;
}