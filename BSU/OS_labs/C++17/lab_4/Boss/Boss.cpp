#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_semaphore.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/thread.hpp>
#include <boost/winapi/process.hpp>
#include <boost/process.hpp>
#include <iostream>
#include <string>
#include "bossfunc.h"
#include <windows.h>


// Create handles for events and semaphore
boost::interprocess::named_mutex eventA(boost::interprocess::open_or_create, "A"),
eventB(boost::interprocess::open_or_create, "B"),
eventC(boost::interprocess::open_or_create, "C"),
eventD(boost::interprocess::open_or_create, "D"),
endOfParent(boost::interprocess::open_or_create, "endP"),
endOfChild(boost::interprocess::open_or_create, "endC");
using namespace std;

int main()
{
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

	boost::process::child* childrens = new boost::process::child[childCount];
	boost::process::child* parents = new boost::process::child[parentCount];
	// Create parent processes
	for (int i = 0; i < parentCount; i++) {
		std::error_code ec;
		std::string commandLine = MakeComLine("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++17\\lab_4\\x64\\Debug\\Parent.exe", parentMessageCount);
		parents[i] = boost::process::child(commandLine);
	}

	// Create child processes
	for (int i = 0; i < childCount; i++)
	{
		std::error_code ec;
		std::string commandLine = MakeComLine("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++17\\lab_4\\x64\\Debug\\Child.exe", childMessageCount);
		childrens[i] = boost::process::child(commandLine);
	}
	int messageCount = 0;
	// Main loop for handling events
	while (true)
	{
		if (endOfChild.try_lock()) {
			// Handle events from parent and child processes
			if (eventC.try_lock())
			{
				messageCount++;
				cout << "Child process shows message C" << endl;
			}
			if (eventD.try_lock())
			{
				messageCount++;
				cout << "Child process shows message D" << endl;
			}
		}
		if (endOfParent.try_lock()) {
			if (eventA.try_lock())
			{
				messageCount++;
				cout << "Parent process shows message A" << endl;
			}
			if (eventB.try_lock())
			{
				messageCount++;
				cout << "Parent process shows message B" << endl;
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
