#include <windows.h>﻿
#include <iostream>
#include "func.h"
#include "boost/thread/thread.hpp"
boost::condition_variable cv;
boost::mutex m;
bool var = false;

// Avoid using namespace std in global scope
// using namespace std;

// Worker thread function
void workerThreadFunc(ArrayStruct* myArray)
{
	// Call the worker function
	ProcessArray(myArray);
	return;
}

// Main thread function
void mainThreadFunc()
{
	ArrayStruct* myArray1;
	int arraySize; // Number of elements in the array

	// Create an array with "arraySize" elements
	int* array = CreateArray(&arraySize);

	std::cout << std::endl;

	// Create a new ArrayStruct object
	myArray1 = new ArrayStruct(array, arraySize, 0);

	// Create a new worker thread
	boost::thread worker(workerThreadFunc, myArray1);
	// Suspend the worker thread
	

	std::cout << "the main  thread is sleeping." << std::endl;

	// Sleep for 1 second
	worker.sleep(boost::get_system_time() + boost::posix_time::milliseconds(1000));
	boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
	std::cout << "the main thread woke up." << std::endl;

	// Wait for the worker thread to finish
	worker.join();
	std::cout << myArray1->NumOfDivByFive;
	return;
}

int main()
{
	// Create a new main thread
	boost::thread thr(mainThreadFunc);

	// Wait for the main thread to finish
	thr.join();

	return 0;
}
