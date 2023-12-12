# Data exchange via an anonymous channel with the process

**Process Server:**
1) The array size is entered from the console. Array type: `int`.
2) Starts the Simple process. 
3) Passes the array size to the Simple process. 
4) Receives array elements from the Simple process;
5) Outputs the received information over the channel to the console.
>

**Process Simple:**
1) Receives the size of the array of numbers over an anonymous channel from the Server process
2) Generates elements of the array
3) Finds and sends simple numbers through an anonymous channel to the Server process.
4) Outputs the obtained numbers to the console.
5) Array elements are passed element by element.
