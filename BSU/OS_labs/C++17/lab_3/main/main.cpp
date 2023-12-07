#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "AllThings.h"

// Global variables
bool isReady = false;
std::mutex mutexCrisec, mutex1, mutex12, mutex2; // Mutexes for different events
std::condition_variable event2, event1; // Condition variables for synchronization

// Structure to hold data
dataStruct *strArray;

// Worker function to process the data
void workerFunction(dataStruct* s)
{
    mutexCrisec.lock(); // Lock the mutex
    std::unique_lock<std::mutex> lock(mutex1); // Lock the mutex
    event1.wait(lock); // Wait for the event
    char* tempArray = new char[s->size]; // Temporary array to hold the data
    std::cout<< " Enter the period of time for sleeping of work stream: ";
    int sleepTime;
    std::cin >> sleepTime; // Get the sleep time from the user
    tempArray = CreateNewArray(s);
    std::cout<< std::endl;
    // Print the temporary array
    DisplayResult(sleepTime, tempArray, s);
    s->array = tempArray; // Update the original array
    mutexCrisec.unlock(); // Unlock the mutex
}

// Function to multiply the elements of the array
void multiplyElementsFunction(dataStruct* s)
{
    std::unique_lock<std::mutex> lock(mutex12); // Lock the mutex
    event1.wait(lock); // Wait for the event
    s->resultMulti = MultiplyNumericElements(s); // Update the result
    while (!isReady) {
        event2.notify_one(); // Notify the event
    }
}

int main()
{
    int arraySize;
    std::cout<< "Enter the size of array: " << std::endl;
    std::cin >> arraySize; // Get the size of the array from the user
    std::cout<< "Enter the elements of array: ";
    char* array = new char[arraySize]; // Allocate memory for the array
    for (int i = 0; i < arraySize; i++)
    {
        std::cin >> array[i]; // Get the array elements from the user
    }
    std::cout << std::endl;
    std::cout << "This is number of elements in array: " << arraySize << std::endl;
    std::cout << "it`s elements: ";
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " "; // Print the array elements
    }
    strArray = new dataStruct(array, arraySize, 1); // Allocate memory for the structure
    std::thread workerThread(workerFunction, strArray); // Create a worker thread
    std::thread multiplyElementsThread(multiplyElementsFunction, strArray); // Create a thread to multiply the elements
    std::cout << "Enter the bounder elements: ";
    std::cin >> strArray->lowerBound >> strArray->upperBound; // Get the bounds from the user
    event1.notify_all(); // Notify the event
    while (mutexCrisec.try_lock())
    {
        mutexCrisec.unlock(); // Unlock the mutex
    }
    mutexCrisec.lock(); // Lock the mutex
    std::cout<< std::endl << "Result of work thread from main: ";
    workerThread.join(); // Wait for the worker thread to finish
    for (int i = 0; i < strArray->size; i++)
    {
        std::cout<< strArray->array[i] << " "; // Print the array elements
    }
    std::cout<< std::endl;
    mutexCrisec.unlock(); // Unlock the mutex
    std::unique_lock<std::mutex> lock2(mutex2); // Lock the mutex
    event2.wait(lock2); // Wait for the event
    isReady = true;
    std::cout<< std::endl << "result of Multi thread from main: ";
    multiplyElementsThread.join(); // Wait for the multiplyElementsThread to finish
    std::cout<< strArray->resultMulti << std::endl; // Print the result
}
