# Synchronization of threads using critical sections and events

This program demonstrates multithreaded array processing in C++ using Windows threads. It includes two threads: a work thread and a multiply element thread.

## What does it do

1. The program first initializes a critical section object and creates two events.
2. It then prompts the user to enter the size and elements of an array.
3. The array information is stored in a structure, which is passed as a parameter to the threads.
4. The work thread waits for the first event to be signaled. It then enters the critical section and prompts the user to enter a sleep time. It creates a new array and displays the result. The array in the structure is then updated with the new array.
5. The multiply element thread also waits for the first event to be signaled. It then enters the critical section and calculates the product of the numeric elements in the array. The product is stored in the structure.
6. Finally, the main function signals the first event and displays the result of the work thread.

**The "main" thread must perform the following actions:** 
1) Initialize the necessary events and critical sections.  
2) Create an array, the elements of which are symbols, the dimension and elements of which are entered by the user from the console or generated randomly;  
3) Output the dimension and elements of the initial array to the console;  
4) Start the work thread  
5) Start the MultElement thread;  
6) Enter values-boundaries A and B.  
7) Notify the work and MultElement threads about the start of work (use the event with manual reset).
8) Receive a signal from the work thread to output the array (use the critical section).
9) Display the result of the work thread's work.
10) Receive a signal from the MultElement thread to output the result (use event2).
11) Display the result of the MultElement thread's work.
12) Synchronization of threads using critical sections and events

**The work thread must perform the following actions:**  
1) Wait for a signal from the main thread to start work (use a manual reset event).  
2) Request from the user the time interval required for rest after preparing one element in the array.  
3) Search the array for elements from the range [A,B] (place them in a new array on the left side, fill the rest of the array with *).  
4) After each prepared element rest for a specified time interval.  
5) Output the elements of the array (the final one) on the screen element by element.  
6) Notify the main thread about outputting the results of the work (the moment of starting will occur after a part of the final array is formed (when all elements from the range [A, B] are found) (use the critical section).

**MultElement thread should perform the following actions (To synchronize with main thread - use manual reset event and event2):**  
Wait for a signal from the main thread about the start of work (use the manual reset event).  
perform the product of the received digits (if any) in the initial array.  
Notify the main thread to output the result (use event2).   
