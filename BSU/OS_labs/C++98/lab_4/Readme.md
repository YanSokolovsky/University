# Synchronization of processes using events, mutexes and semaphores  

**Boss process:**
1) Synchronization Object Initialization.  
2) Asks the user for the number of Parent processes and the number of Child processes to be started.  
3) Asks for the number of messages received from Parent or Child.  
4) Starts the specified number of Parent, Child processes.  
5) Receives messages from each Parent, Child process, outputs them and who sent them to the console in one line.
> ```HANDLE mutex;  
> // Create semaphore and events  
>	semaphore = CreateSemaphore(NULL, 2, 2, "semaphore"); // Create a semaphore with initial and maximum count of 2  
>	eventA = CreateEvent(NULL, FALSE, FALSE, "eventA"); // Create an auto-reset event object for eventA  
>	eventB = CreateEvent(NULL, FALSE, FALSE, "eventB"); // Create an auto-reset event object for eventB  
>	eventC = CreateEvent(NULL, FALSE, FALSE, "eventC"); // Create an auto-reset event object for eventC  
>	eventD = CreateEvent(NULL, FALSE, FALSE, "eventD"); // Create an auto-reset event object for eventD  
>	endOfParent = CreateEvent(NULL, FALSE, FALSE, "endOfParent"); // Create an auto-reset event object for endOfParent  
>	endOfChild = CreateEvent(NULL, FALSE, FALSE, "endOfChild"); // Create an auto-reset event object for endOfChild  
>	mutex = CreateMutex(NULL, FALSE, "mutex"); // Create a mutex object```

**Parent process:**  
1) Synchronize the work of Parent processes with the help of mutex.  
2) Realize message passing with the help of events.  
3) Requests messages consisting of "A" or "B" from the console and passes them (one by one) to the Boss process.  

**Child process:**
1) Synchronize the operation of Child processes using a semaphore.  
2) Realize message passing by means of events.  
3) Requests messages consisting of "C" or "D" from the console and passes them (one by one) to the Boss process.  
