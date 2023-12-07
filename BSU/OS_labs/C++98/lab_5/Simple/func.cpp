#include "func.h" // Include the header file "func.h"
#include <cmath> // Include the cmath library for sqrt function

// Function to generate an array of random numbers
int* GenerateRandom(int arraySize)
{
    if (arraySize <= 0)
    {
        return NULL;
    }
    srand(time(NULL)); // Seed the random number generator with the current time
    int* randomArray = new int[arraySize]; // Allocate memory for an array of integers
    for (int index = 0; index < arraySize; index++) // Loop through each element of the array
    {
        randomArray[index] = rand() % 100; // Assign a random number between 0 and 99 to each element
    }
    return randomArray; // Return the array of random numbers
}

// Function to check if a number is prime
bool checkPrime(int number)
{
    if (number <= 1) // If the number is 1 or less, it's not prime
    {
        return false;
    }
    if (number == 2) // If the number is equal to 2, it`s prime
    {
        return true;
    }
    int primeFlag = 0; // Flag to indicate if the number is prime
    for (int divisor = 2; divisor <= static_cast<int>(std::sqrt(static_cast<double>(number))) + 1; divisor++) // Loop from 2 to the square root of the number
    {
        if (number % divisor == 0) // If the number is divisible by the divisor, it's not prime
        {
            primeFlag = 1;
        }
    }
    if (primeFlag == 1) // If the flag is set, the number is not prime
        return false;
    return true; // If the flag is not set, the number is prime
}
