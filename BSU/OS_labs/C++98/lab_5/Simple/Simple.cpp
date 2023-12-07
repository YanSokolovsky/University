#include <iostream>
#include <windows.h>
#include "func.h"
#include <string>

int main(int argc, char* argv[])
{
    // Define handles for writing and reading, and events for work and size entry
    HANDLE writeHandle, readHandle, simpleWorkEvent, serverWorkEvent, sizeInputEvent, endOfArrayEvent;

    // Open the event for simple work
    simpleWorkEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, "simpleWorkEvent");
    if (simpleWorkEvent == NULL)
    {
        return GetLastError();
    }

    // Open the event for server work
    serverWorkEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, "serverWorkEvent");
    if (serverWorkEvent == NULL)
    {
        return GetLastError();
    }

    // Open the event for size entry
    sizeInputEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, "sizeInputEvent");
    if (sizeInputEvent == NULL)
    {
        return GetLastError();
    }

    // Open the event for end of mass
    endOfArrayEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, "endOfArrayEvent");
    if (endOfArrayEvent == NULL)
    {
        return GetLastError();
    }

    // Convert the first and second command line arguments to handles for writing and reading
    writeHandle = (HANDLE)atoi(argv[1]);
    readHandle = (HANDLE)atoi(argv[2]);

    // Initialize the size of the array
    int arraySize = 0;

    // Wait for the size entry event
    WaitForSingleObject(sizeInputEvent, INFINITE);

    // Define a pointer for trash
    LPDWORD trash = 0;

    // Read the size of the array from the pipe
    if (!ReadFile(readHandle, &arraySize, sizeof(arraySize), trash, NULL))
    {
        std::cout << "Reading from the pipe is failde.";
        std::cout << "Enter any cahracter." << std::endl;
        char f;
        std::cin >> f;
        CloseHandle(serverWorkEvent);
        CloseHandle(simpleWorkEvent);
        CloseHandle(endOfArrayEvent);
        CloseHandle(sizeInputEvent);
        CloseHandle(writeHandle);
        CloseHandle(readHandle);
        return GetLastError();
    }

    // Generate a random array of the given size
    int* array = GenerateRandom(arraySize);
    std::cout << std::endl;

    // Iterate over the array
    for (int i = 0; i < arraySize; i++)
    {
        // If the current element is prime
        if (checkPrime(array[i]))
        {
            // Print the current element
            std::cout << array[i] << " ";

            // Wait for the simple work event
            WaitForSingleObject(simpleWorkEvent, INFINITE);

            // Reset the simple work event
            ResetEvent(simpleWorkEvent);

            // Write the current element to the pipe
            if (!WriteFile(writeHandle, &array[i], sizeof(int), trash, NULL))
            {
                std::cout << "Writing to the pipe is failde.";
                std::cout << "Enter any cahracter." << std::endl;
                char f;
                std::cin >> f;
                CloseHandle(serverWorkEvent);
                CloseHandle(simpleWorkEvent);
                CloseHandle(endOfArrayEvent);
                CloseHandle(sizeInputEvent);
                CloseHandle(writeHandle);
                CloseHandle(readHandle);
                return GetLastError();
            }

            // Sleep for 200 milliseconds
            Sleep(200);

            // Set the server work event
            SetEvent(serverWorkEvent);
        }
    }

    // If the simple work event is signaled
    if (WaitForSingleObject(simpleWorkEvent, INFINITE) == WAIT_OBJECT_0)
        // Set the end of mass event
        SetEvent(endOfArrayEvent);

    // Set the server work event
    SetEvent(serverWorkEvent);

    // Close all handles and events
    CloseHandle(serverWorkEvent);
    CloseHandle(simpleWorkEvent);
    CloseHandle(endOfArrayEvent);
    CloseHandle(sizeInputEvent);
    CloseHandle(writeHandle);
    CloseHandle(readHandle);

    // Wait for user input before exiting
    char f;
    std::cin >> f;
}
