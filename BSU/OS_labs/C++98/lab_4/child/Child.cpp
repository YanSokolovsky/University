#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>

// Declare handles for semaphore and events
HANDLE semaphore, eventC, eventD, endOfChild;

// Declare a critical section object
CRITICAL_SECTION criticalSectionA;

using namespace std;

int main(int argc, char* argv[])
{
	// Create a semaphore with initial and maximum count of 2
	semaphore = CreateSemaphore(NULL, 2, 2, "semaphore");

	// Create events for 'C', 'D', and 'endOfChild'
	eventC = CreateEvent(NULL, FALSE, FALSE, "eventC");
	eventD = CreateEvent(NULL, FALSE, FALSE, "eventD");
	endOfChild = CreateEvent(NULL, FALSE, FALSE, "endOfChild");

	// Convert the last command line argument to integer
	int num = atoi(argv[argc - 1]);

	// Check if events were created successfully
	if (eventC == NULL)
		return GetLastError();
	if (eventD == NULL)
		return GetLastError();
	if (endOfChild == NULL)
		return GetLastError();

	// Check if semaphore was created successfully
	if (semaphore == NULL)
	{
		cout << "Create semaphore failed." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();
		return GetLastError();
	}

	// Wait for the semaphore to become signaled
	WaitForSingleObject(semaphore, INFINITE);

	// Loop 'num' times
	for (int i = 0; i < num; i++) {
		cout << "Enter the message for Boss window: ";
		char inputChar;
		cin >> inputChar;
		cout << endl;

		// Set events based on user input
		if (inputChar == 'C')
		{
			SetEvent(eventC);
		}
		if (inputChar == 'D')
		{
			SetEvent(eventD);
		}

		// Signal that a child event has ended
		SetEvent(endOfChild);
	}

	// Release the semaphore
	ReleaseSemaphore(semaphore, 1, NULL);

	// Close the handles to the events
	CloseHandle(endOfChild);
	CloseHandle(eventC);
	CloseHandle(eventD);

	return 0;
}
