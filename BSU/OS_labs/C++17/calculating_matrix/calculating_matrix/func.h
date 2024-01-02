#pragma once
#include <boost/thread/mutex.hpp>
struct matrix {
    int numberofrows;
    int numberoflines;
    int** mat;
    boost::mutex** matofmut;
    bool** matof;
    matrix(int a, int b);
    int* operator[] (int a);
    bool done;
};
void calculate(matrix* result, matrix* mat1, matrix* mat2, int linecoordinate, int rowcoordinate);