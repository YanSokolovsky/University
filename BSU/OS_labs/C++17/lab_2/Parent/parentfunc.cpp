#include "parentfunc.h"
#include <string>

// Function to create a command line string from an array of strings
std::string createCommandLineString(std::string executableName, std::string* array, int arraySize)
{
    // Start the command line string with the name of the executable
    std::string commandLine = executableName;

    // Append each element of the array to the command 
    // line string, separated by spaces
    for (int i = 0; i < arraySize; i++)
    {
        commandLine.append(" ");
        commandLine.append(array[i]);
    }

    // Return the final command line string
    return commandLine;
};
