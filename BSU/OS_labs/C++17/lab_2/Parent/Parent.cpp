#include "parentfunc.h"
#include "boost/process.hpp"
int main()
{
    // User to enter the size of the array
    std::cout << "Enter the size of array: " << std::endl;
    int arraySize;
    std::cin >> arraySize;

    // Create a new string array of the given size
    std::string* array = new std::string[arraySize];

    // User to enter the elements of the array
    std::cout << "Enter the elements of our array: " << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cin >> array[i];
    }

    // User to enter the number of pixels from the top left corner
    std::cout << "Enter the number of pixels from left high corner: " << std::endl;
    int windowPosition;
    std::cin >> windowPosition;

    // Create a new process
    
    boost::process::child c(createCommandLineString("C:\\Users\\wexes\\source\\repos\\BSU\\OS_labs\\C++17\\lab_2\\x64\\Debug\\Child.exe",
        array, arraySize));
    if (!c.valid())
    {
        std::cout << "The new process is not created." << std::endl;
        std::cout << "Check the name of the process." << std::endl;
        std::cout << "Press any key to finish." << std::endl;
        char waitInput;
        std::cin >> waitInput;
        return 0;
    }
    // Wait for the created process to finish, then close the 
    // process and thread handles
    c.join();

    return 0;
}
