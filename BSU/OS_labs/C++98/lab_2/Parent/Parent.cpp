#include "parentfunc.h"

int main()
{
    // User to enter the size of the array
    std::cout << "Enter the size of array: " << std::endl;
    int arraySize;
    std::cin >> arraySize;

    // Create a new string array of the given size
    std::string* array = new std::string[arraySize];

    // User to enter the elements of the array
    std::cout << "Enter the elements of our array: " << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cin >> array[i];
    }

    // User to enter the number of pixels from the top left corner
    std::cout << "Enter the number of pixels from left high corner: " << std::endl;
    int windowPosition;
    std::cin >> windowPosition;

    // Initialize the STARTUPINFO and PROCESS_INFORMATION structures
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
    startupInfo.cb = sizeof(STARTUPINFO);
    startupInfo.dwX = windowPosition;
    startupInfo.dwFlags = STARTF_USEPOSITION;

    // Create a new process
    if (!CreateProcess(NULL, const_cast<char*>(createCommandLineString("Child.exe",
        array, arraySize).c_str()),
        NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
    {
        // If the process creation fails, print an error message
        //  and wait for user input before exiting
        std::cout << "The new process is not created." << std::endl;
        std::cout << "Check the name of the process." << std::endl;
        std::cout << "Press any key to finish." << std::endl;
        char waitInput;
        std::cin >> waitInput;
        return 0;
    }

    // Wait for the created process to finish, then close the 
    // process and thread handles
    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess);

    return 0;
}
