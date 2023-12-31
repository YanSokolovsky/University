#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_semaphore.hpp>
#include <boost/interprocess/sync/named_condition.hpp>﻿
#include <iostream>
#include <string>
boost::interprocess::named_mutex
eventA(boost::interprocess::open_or_create, "A"),
eventB(boost::interprocess::open_or_create, "B"),
endOfParent(boost::interprocess::open_or_create, "endP"),
mut(boost::interprocess::open_or_create, "mutex");
using namespace std;

int main(int argc, char* argv[])
{
	// Convert the last command line argument to an integer
	int messageCount = atoi(argv[argc - 1]);

	// Acquire the mutex
	mut.lock();

	for (int i = 0; i < messageCount; i++) {
		cout << "Enter the message for Boss window: ";
		char message;
		cin >> message;
		cout << endl;

		// Set the appropriate event based on the entered message
		if (message == 'A')
		{
			eventA.unlock();
		}
		if (message == 'B')
		{
			eventB.unlock();
		}

		// Signal that a message has been sent
		endOfParent.unlock();
	}
	// Release the mutex
	mut.unlock();
	return 0;
}