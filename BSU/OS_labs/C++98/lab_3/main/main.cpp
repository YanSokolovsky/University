#include <windows.h>
#include <iostream>
#include "func.h"

// Critical section object
CRITICAL_SECTION criticalSection;

// Handles for events and threads
HANDLE event1, event2, workThread, multiplyElementThread;

// Thread IDs
DWORD workThreadId, multiplyElementThreadId;

// Pointer to array information
ArrayInfo* arrayInfo;

// Function for the work thread
DWORD WINAPI workFunction(LPVOID st)
{
    // Wait for event1 to be signaled
    WaitForSingleObject(event1, INFINITE);

    // Cast the passed parameter to ArrayInfo pointer
    ArrayInfo* s = static_cast<ArrayInfo*>(st);

    // Reset event1
    ResetEvent(event1);

    // Enter the critical section
    EnterCriticalSection(&criticalSection);

    // Prompt for and read the sleep time for the work thread
    std::cout << " Enter the period of time for sleeping of work stream: ";
    int time;
    std::cin >> time;

    // Create a new array and display the result
    char* array = CreateNewArray(s);
    std::cout << std::endl;
    DisplayResult(time, array, s);

    // Update the array in the passed structure
    s->array = array;

    // Leave the critical section
    LeaveCriticalSection(&criticalSection);

    return 0;
}

// Function for the multiply element thread
DWORD WINAPI multiplyElementFunction(LPVOID st)
{
    // Wait for event1 to be signaled
    WaitForSingleObject(event1, INFINITE);

    // Sleep for a second
    Sleep(1000);

    // Enter the critical section
    EnterCriticalSection(&criticalSection);

    // Cast the passed parameter to ArrayInfo pointer
    ArrayInfo* s = static_cast<ArrayInfo*>(st);

    // Calculate the product of numeric elements in the array
    s->product = MultiplyNumericElements(s);

    // Leave the critical section
    LeaveCriticalSection(&criticalSection);

    // Signal event2
    SetEvent(event2);

    return 0;
}

int main()
{
    // Initialize the critical section
    InitializeCriticalSection(&criticalSection);

    // Create event1
    event1 = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (event1 == NULL)
        return GetLastError();

    // Create event2
    event2 = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (event2 == NULL)
        return GetLastError();

    // Prompt for and read the size of the array
    int n;
    std::cout << "Enter the size of array: " << std::endl;
    std::cin >> n;

    // Prompt for and read the elements of the array
    std::cout << "Enter the elements of array: ";
    char* array = new char[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    std::cout << std::endl;

    // Display the number of elements in the array
    std::cout << "This is number of elements in array: " << n << std::endl;

    // Display the elements of the array
    std::cout << "it`s elements: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }

    // Allocate and initialize the array information structure
    arrayInfo = new ArrayInfo;
    arrayInfo->array = array;
    arrayInfo->size = n;

    // Create the work thread
    workThread = CreateThread(NULL, 0, workFunction, static_cast<LPVOID>(arrayInfo), 0, &workThreadId);
    if (workThread == NULL)
        return GetLastError();

    // Create the multiply element thread
    multiplyElementThread = CreateThread(NULL, 0, multiplyElementFunction, static_cast<LPVOID>(arrayInfo), 0, &multiplyElementThreadId);
    if (multiplyElementThread == NULL)
        return GetLastError();

    // Prompt for and read the boundary elements
    std::cout << "Enter the boundary elements: ";
    std::cin >> arrayInfo->upperBound >> arrayInfo->lowerBound;

    // Signal event1
    SetEvent(event1);

    // Sleep for a second
    Sleep(1000);

    // Enter the critical section
    EnterCriticalSection(&criticalSection);

    // Display the result of the work thread
    std::cout << std::endl << "Result of work thread from main: ";
    for (int i = 0; i < arrayInfo->size; i++)
    {
        std::cout << arrayInfo->array[i] << " ";
    }

    // Leave the critical section
    LeaveCriticalSection(&criticalSection);

    // Wait for event2 to be signaled
    WaitForSingleObject(event2, INFINITE);

    // Display the result of the multiply element thread
    std::cout << std::endl << "result of Multi thread from main: ";
    std::cout << arrayInfo->product;

    // Delete the critical section
    DeleteCriticalSection(&criticalSection);

    // Wait for the threads to terminate
    WaitForSingleObject(workThread, INFINITE);
    WaitForSingleObject(multiplyElementThread, INFINITE);

    // Close the handles
    CloseHandle(workThread);
    CloseHandle(multiplyElementThread);
    CloseHandle(event1);
    CloseHandle(event2);
}
