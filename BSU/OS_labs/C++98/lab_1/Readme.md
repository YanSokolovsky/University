# Creating threads

**The "mainThreadFunc" thread:**  
1) Creates an array of integers.  
2) Requests the stop time of the "work" thread. `CreateThread()`

**Thread "workerThreadFunc":**  
1) Outputs the number of elements divisible by 5.
