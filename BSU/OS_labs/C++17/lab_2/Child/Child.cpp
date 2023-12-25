#include "childfunc.h"

int main(int argc, char* argv[])
{
    // Create an array from the command line arguments
    int* numbers = createArrayFromArgs(argv, argc);

    // Sort the array
    quickSort(numbers, 0, argc - 2);

    // Print the sorted array
    for (int i = 0; i < argc - 1; i++)
    {
        std::cout << numbers[i] << " ";
    }

    // Wait for user input before exiting
    char exitInput;
    std::cin >> exitInput;

    return 0;
}
