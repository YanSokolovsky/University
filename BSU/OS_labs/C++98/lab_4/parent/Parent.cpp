#include <iostream>
#include <windows.h>
#include <string>

// Create handles for events
HANDLE eventA, eventB, endOfParent;
using namespace std;

int main(int argc, char* argv[])
{
	HANDLE mutex;
	// Create events
	eventA = CreateEvent(NULL, FALSE, FALSE, "eventA");
	eventB = CreateEvent(NULL, FALSE, FALSE, "eventB");
	endOfParent = CreateEvent(NULL, FALSE, FALSE, "endOfParent");

	// Open mutex
	mutex = OpenMutex(SYNCHRONIZE, FALSE, "mutex");

	// Convert the last command line argument to an integer
	int messageCount = atoi(argv[argc - 1]);

	if (eventA == NULL)
		return GetLastError();
	if (eventB == NULL)
		return GetLastError();
	if (endOfParent == NULL)
		return GetLastError();
	if (mutex == NULL)
	{
		cout << "Create mutex failed." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();
		return GetLastError();
	}

	// Acquire the mutex
	WaitForSingleObject(mutex, INFINITE);

	for (int i = 0; i < messageCount; i++) {
		cout << "Enter the message for Boss window: ";
		char message;
		cin >> message;
		cout << endl;

		// Set the appropriate event based on the entered message
		if (message == 'A')
		{
			SetEvent(eventA);
		}
		if (message == 'B')
		{
			SetEvent(eventB);
		}

		// Signal that a message has been sent
		SetEvent(endOfParent);
	}

	// Release the mutex
	ReleaseMutex(mutex);

	// Close the handles
	CloseHandle(endOfParent);
	CloseHandle(eventB);
	CloseHandle(eventA);

	return 0;
}
