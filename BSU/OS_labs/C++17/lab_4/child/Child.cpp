#include <iostream>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_semaphore.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <time.h>
#include <string>

// Declare handles for semaphore and events
boost::interprocess::named_mutex
eventC(boost::interprocess::open_or_create, "C"),
eventD(boost::interprocess::open_or_create, "D"),
endOfChild(boost::interprocess::open_or_create, "endC");


// Declare a critical section object

using namespace std;

int main(int argc, char* argv[])
{
	// Create a semaphore with initial and maximum count of 2
	boost::interprocess::named_semaphore sem(boost::interprocess::open_or_create, "sem", 2, nullptr);

	// Convert the last command line argument to integer
	int num = atoi(argv[argc - 1]);

	// Wait for the semaphore to become signaled
	sem.wait();

	// Loop 'num' times
	for (int i = 0; i < num; i++) {
		cout << "Enter the message for Boss window: ";
		char inputChar;
		cin >> inputChar;
		cout << endl;

		// Set events based on user input
		if (inputChar == 'C')
		{
			eventC.unlock();
		}
		if (inputChar == 'D')
		{
			eventD.unlock();
		}

		// Signal that a child event has ended
		endOfChild.unlock();
	}

	// Release the semaphore
	sem.post();

	return 0;
}