#pragma once
struct dataStruct
{
    char* array;
    int size;
    char lowerBound;
    char upperBound;
    int resultMulti;
    dataStruct(char* arra, int siz, int resmulti);
};
int MultiplyNumericElements(dataStruct* s);
char* CreateNewArray(dataStruct* s);
void DisplayResult(int delay, char* newArray, dataStruct* s);
