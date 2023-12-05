#include <windows.h>
#include <iostream>
#include "func.h"

// Avoid using namespace std in global scope
// using namespace std;

// Worker thread function
DWORD WINAPI workerThreadFunc(LPVOID param)
{
	// Cast the input parameter to the correct type
	ArrayStruct* myArray = static_cast<ArrayStruct*>(param);

	// Call the worker function
	ProcessArray(myArray);

	return 0;
}

// Main thread function
DWORD WINAPI mainThreadFunc(LPVOID param)
{
	ArrayStruct* myArray1;
	int arraySize; // Number of elements in the array

	// Create an array with "arraySize" elements
	int* array = CreateArray(&arraySize);

	std::cout << std::endl;

	// Create a new ArrayStruct object
	myArray1 = new ArrayStruct(array, arraySize, 0);

	DWORD threadID;
	HANDLE workerThread;

	// Create a new worker thread
	workerThread = CreateThread(NULL, 0, workerThreadFunc, static_cast<void*>(myArray1), 0, &threadID);

	if (workerThread == 0)
		return 0;

	// Suspend the worker thread
	SuspendThread(workerThread);

	std::cout << "the main  thread is sleeping." << std::endl;

	// Sleep for 1 second
	Sleep(1000);

	std::cout << "the main thread woke up." << std::endl;

	// Resume the worker thread
	ResumeThread(workerThread);

	// Wait for the worker thread to finish
	WaitForSingleObject(workerThread, INFINITE);

	std::cout << myArray1->NumOfDivByFive;

	if (workerThread == 0)
		return 0;

	// Close the handle to the worker thread
	CloseHandle(workerThread);

	return 0;
}

int main()
{
	DWORD mainThreadID;
	HANDLE mainThread;
	int unusedParam = 0;

	// Create a new main thread
	mainThread = CreateThread(NULL, 0, mainThreadFunc, (void*)&unusedParam, 0, &mainThreadID);

	if (mainThread == NULL)
		return GetLastError();

	// Wait for the main thread to finish
	WaitForSingleObject(mainThread, INFINITE);

	// Close the handle to the main thread
	CloseHandle(mainThread);

	return 0;
}
