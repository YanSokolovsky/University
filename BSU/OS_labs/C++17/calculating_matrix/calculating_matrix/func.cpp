#include "func.h"
#include <boost/thread/mutex.hpp>
matrix::matrix(int a, int b) {
    done = false;
    numberofrows = a;
    numberoflines = b;
    mat = new int* [numberoflines];
    matofmut = new boost::mutex * [numberoflines];
    matof = new bool* [numberoflines];
    for (int i = 0; i < numberoflines; i++)
    {
        mat[i] = new int[numberofrows];
        for (int y = 0; y < numberoflines; y++)
        {
            mat[i][y] = 0;
        }
    }
    for (int i = 0; i < numberoflines; i++)
    {
        matofmut[i] = new boost::mutex[numberofrows];
    }
    for (int i = 0; i < numberoflines; i++)
    {
        matof[i] = new bool[numberofrows];
        for (int y = 0; y < numberofrows; y++)
        {
            matof[i][y] = false;
        }
    }
}
int* matrix::operator[] (int a) {
    return mat[a];
}
void calculate(matrix* result, matrix* mat1, matrix* mat2, int linecoordinate, int rowcoordinate)
{
    for (int i = 0; i < mat1->numberofrows; i++)
    {
        result->mat[linecoordinate][rowcoordinate] += mat1->mat[linecoordinate][i] * mat2->mat[i][rowcoordinate];
    }
    result->matof[linecoordinate][rowcoordinate] = true;
    result->matofmut[linecoordinate][rowcoordinate].unlock();
};