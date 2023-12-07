#include <windows.h>
#include <iostream>

int main()
{
    // Prompt user to enter the size of the array
    std::cout << "Enter size of array, please ";
    int arraySize;
    std::cin >> arraySize;

    // Create handles for writing and reading from the pipe, and for various events
    HANDLE writeHandle, readHandle, simpleWorkEvent, serverWorkEvent, sizeInputEvent, endOfArrayEvent;

    // Create an event to allow the simple process to work
    simpleWorkEvent = CreateEvent(NULL, FALSE, FALSE, "simpleWorkEvent");
    if (simpleWorkEvent == NULL)
    {
        return GetLastError();
    }

    // Create an event to signal that the size has been entered
    sizeInputEvent = CreateEvent(NULL, FALSE, FALSE, "sizeInputEvent");
    if (sizeInputEvent == NULL)
    {
        return GetLastError();
    }

    // Create an event to allow the server process to work
    serverWorkEvent = CreateEvent(NULL, FALSE, FALSE, "serverWorkEvent");
    if (serverWorkEvent == NULL)
    {
        return GetLastError();
    }

    // Create an event to signal the end of the array
    endOfArrayEvent = CreateEvent(NULL, FALSE, FALSE, "endOfArrayEvent");
    if (endOfArrayEvent == NULL)
    {
        return GetLastError();
    }

    // Initialize the startup info and process info structures
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    SECURITY_ATTRIBUTES securityAttr;
    securityAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    securityAttr.lpSecurityDescriptor = NULL;
    securityAttr.bInheritHandle = TRUE;

    ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
    startupInfo.cb = sizeof(STARTUPINFO);

    // Create a pipe for inter-process communication
    if (!CreatePipe(&readHandle, &writeHandle, &securityAttr, 0))
    {
        std::cout << "Create pipe failed.\n";
        char exitChar;
        std::cout << "Enter any character." << std::endl;
        std::cin >> exitChar;
        return GetLastError();
    }

    // Prepare the command line for creating the simple process
    char commandLine[80];
    wsprintf(commandLine, "Simple.exe %d %d", (int)writeHandle, (int)readHandle);

    // Create the simple process
    if (!CreateProcess(NULL, commandLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
    {
        std::cout << "Creating process failed." << std::endl;
        char exitChar;
        std::cout << "Enter any character." << std::endl;
        std::cin >> exitChar;
        return GetLastError();
    }

    // Write the size of the array to the pipe
    int numberOfWrittenBytes = 0;

    if (!WriteFile(writeHandle, &arraySize, sizeof(int), (LPDWORD)numberOfWrittenBytes, NULL))
    {
        std::cout << "Writing to the pipe is failed.";
        std::cout << "Enter any character." << std::endl;
        char exitChar;
        std::cin >> exitChar;
        return GetLastError();
        CloseHandle(serverWorkEvent);
        CloseHandle(simpleWorkEvent);
        CloseHandle(endOfArrayEvent);
        CloseHandle(sizeInputEvent);
        CloseHandle(writeHandle);
        CloseHandle(readHandle);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    }

    std::cout << std::endl;
    SetEvent(sizeInputEvent);
    SetEvent(simpleWorkEvent);

    // Main loop for reading data from the pipe
    do
    {
        if (WaitForSingleObject(serverWorkEvent, INFINITE) == WAIT_OBJECT_0)
        {
            ResetEvent(serverWorkEvent);

            if (WaitForSingleObject(endOfArrayEvent, 0) != WAIT_OBJECT_0)
            {
                int data = 0;
                LPDWORD trash = 0;

                if (!ReadFile(readHandle, &data, sizeof(int), trash, NULL))
                {
                    std::cout << "Reading from the pipe is failed.";
                    std::cout << "Enter any character." << std::endl;
                    char exitChar;
                    std::cin >> exitChar;
                    return GetLastError();
                    CloseHandle(serverWorkEvent);
                    CloseHandle(simpleWorkEvent);
                    CloseHandle(endOfArrayEvent);
                    CloseHandle(sizeInputEvent);
                    CloseHandle(writeHandle);
                    CloseHandle(readHandle);
                    CloseHandle(processInfo.hProcess);
                    CloseHandle(processInfo.hThread);
                }

                std::cout << data << " ";
                SetEvent(simpleWorkEvent);
            }
            else
            {
                break;
            }
        }
    } while (true);

    // Close all handles
    CloseHandle(serverWorkEvent);
    CloseHandle(simpleWorkEvent);
    CloseHandle(endOfArrayEvent);
    CloseHandle(sizeInputEvent);
    CloseHandle(writeHandle);
    CloseHandle(readHandle);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
}
