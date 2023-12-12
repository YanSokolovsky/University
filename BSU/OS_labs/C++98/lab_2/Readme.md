# Creating process

**Parent process:**  
1) Enter the array size, enter the array elements;  
2) Set windowPosition, offset from the top left corner of the screen.  
3) Forms a command line that contains information about the array size, elements.  
4) For the child process console "Child" sets (STARTUPINFO) visual settings.
> `STARTUPINFO startupInfo;`  
> `PROCESS_INFORMATION processInfo;`  
> `ZeroMemory(&startupInfo, sizeof(STARTUPINFO));`  
> `startupInfo.cb = sizeof(STARTUPINFO);`  
> `startupInfo.dwX = windowPosition;`  
> `startupInfo.dwFlags STARTF_USEPOSITION;`  

**Child process:**  
1) Hoare Sort. `quickSort`  
2) Output the resulting array of integers to its own console.  
