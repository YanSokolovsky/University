#include <iostream>
#include <windows.h>
#include <string>
#include "bossfunc.h"

// Create handles for events and semaphore
HANDLE eventA, eventB, eventC, eventD, endOfParent, endOfChild, semaphore;
using namespace std;

int main()
{
	HANDLE mutex;
	// Create semaphore and events
	semaphore = CreateSemaphore(NULL, 2, 2, "semaphore"); // Create a semaphore with initial and maximum count of 2
	eventA = CreateEvent(NULL, FALSE, FALSE, "eventA"); // Create an auto-reset event object for eventA
	eventB = CreateEvent(NULL, FALSE, FALSE, "eventB"); // Create an auto-reset event object for eventB
	eventC = CreateEvent(NULL, FALSE, FALSE, "eventC"); // Create an auto-reset event object for eventC
	eventD = CreateEvent(NULL, FALSE, FALSE, "eventD"); // Create an auto-reset event object for eventD
	endOfParent = CreateEvent(NULL, FALSE, FALSE, "endOfParent"); // Create an auto-reset event object for endOfParent
	endOfChild = CreateEvent(NULL, FALSE, FALSE, "endOfChild"); // Create an auto-reset event object for endOfChild
	mutex = CreateMutex(NULL, FALSE, "mutex"); // Create a mutex object

	int parentCount;
	int childCount;
	int childMessageCount;
	int parentMessageCount;

	cout << "Enter the number of all parent processes ";
	cin >> parentCount;
	cout << "Enter the number of messages from parent processes ";
	cin >> parentMessageCount;
	cout << "Enter the number of all child processes ";
	cin >> childCount;
	cout << "Enter the number of messages from child processes ";
	cin >> childMessageCount;
	cout << endl;

	// Create arrays for storing process information
	STARTUPINFO* startupInfoParent = new STARTUPINFO[parentCount];
	PROCESS_INFORMATION* processInfoParent = new PROCESS_INFORMATION[parentCount];
	HANDLE* parentHandles = new HANDLE[parentCount];

	STARTUPINFO* startupInfoChild = new STARTUPINFO[childCount];
	PROCESS_INFORMATION* processInfoChild = new PROCESS_INFORMATION[childCount];
	HANDLE* childHandles = new HANDLE[childCount];

	// Create parent processes
	for (int i = 0; i < parentCount; i++) {
		startupInfoParent[i] = ZeroStart();
		char* commandLine = MakeComLine("Parent.exe", parentMessageCount);
		if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfoParent[i], &processInfoParent[i]))
		{
			cout << "The new Parent process is not created.\n";
			return 0;
		}
		parentHandles[i] = processInfoParent[i].hProcess;
	}

	// Create child processes
	for (int i = 0; i < childCount; i++)
	{
		startupInfoChild[i] = ZeroStart();
		char* commandLine = MakeComLine("Child.exe", childMessageCount);
		if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfoChild[i], &processInfoChild[i]))
		{
			cout << "The new Child process is not created.\n";
			return 0;
		}
		childHandles[i] = processInfoChild[i].hProcess;
	}

	int messageCount = 0;
	// Main loop for handling events
	while (true)
	{
		// Check if any parent or child process has ended
		if (WaitForSingleObject(endOfParent, 0) == WAIT_OBJECT_0 || WaitForSingleObject(endOfChild, 0)) {
			// Handle events from parent and child processes
			if (WaitForSingleObject(eventA, 0) == WAIT_OBJECT_0)
			{
				messageCount++;
				cout << "Parent process shows message A" << endl;
			}
			if (WaitForSingleObject(eventB, 0) == WAIT_OBJECT_0)
			{
				messageCount++;
				cout << "Parent process shows message B" << endl;
			}
			if (WaitForSingleObject(eventC, 0) == WAIT_OBJECT_0)
			{
				messageCount++;
				cout << "Child process shows message C" << endl;
			}
			if (WaitForSingleObject(eventD, 0) == WAIT_OBJECT_0)
			{
				messageCount++;
				cout << "Child process shows message D" << endl;
			}
		}
		// Break the loop if all messages have been handled
		if (messageCount >= parentCount * parentMessageCount + childCount * childMessageCount)
		{
			break;
		}
	}
	return 0;
}
