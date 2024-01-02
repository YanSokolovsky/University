Develop a multithreaded application that computes the product of matrices A (m×n) and B (n×k).
The elements cij of the product matrix C = A×B are computed in parallel by p threads of the same type.
If some thread already computes the element cij of the matrix C, the next thread that starts the computation chooses the element cij+1 if j<k and ci+1k if j=k. 
Having calculated the element of the matrix-derivative, the thread checks if there is an element that is not yet calculated.
If there is such an element, it proceeds to its calculation. Otherwise, it sends a (user) message about the completion of its work and suspends its execution.
The main thread, having received messages about the completion of calculations from all threads, 
displays the result on the screen and starts a thread that writes the result to the end of the protocol file. 
Each thread must have a delay in performing calculations (to give all threads a chance to work).
