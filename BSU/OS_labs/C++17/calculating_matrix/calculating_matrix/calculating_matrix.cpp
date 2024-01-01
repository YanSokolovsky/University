﻿#include <boost\thread\mutex.hpp>
#include <boost\thread.hpp>
#include <iostream>
#include <fstream>

boost::mutex start;
using namespace std;
struct matrix {
    int numberofrows;
    int numberoflines;
    int** mat;
    boost::mutex** matofmut;
    bool** matof;
    matrix(int a, int b) {
        numberofrows = a;
        numberoflines = b;
        mat = new int*[numberoflines];
        matofmut = new boost::mutex*[numberoflines];
        matof = new bool*[numberoflines];
        for (int i = 0; i < numberoflines; i++)
        {
            mat[i] = new int[numberofrows];
        }
        for (int i = 0; i < numberoflines; i++)
        {
            matofmut[i] = new boost::mutex[numberofrows];
        }
        for (int i = 0 ; i < numberoflines; i++)
        {
            matof[i] = new bool[numberofrows];
            for (int y = 0; y < numberofrows; y++)
            {
                matof[i][y] = false;
            }
        }
        done = false;
    }
    int* operator[] (int a) {
        return mat[a];
    }
    bool done;
};
void worker(matrix* result, matrix* mat1, matrix* mat2, int startpoint)
{
    int t = startpoint;
    int linecoordinate = (t + result->numberofrows - 1) / result->numberofrows - 1;
    int rowcoordinate = (t - 1) % result->numberofrows;
    while (result->numberoflines * result->numberofrows >= t)
    {
        if (!result->matof[linecoordinate][rowcoordinate] && result->matofmut[linecoordinate][rowcoordinate].try_lock())
        {
            result->mat[linecoordinate][rowcoordinate] = 0;
            for (int i = 0; i < mat1->numberofrows; i++)
            {
                result->mat[linecoordinate][rowcoordinate] += mat1->mat[linecoordinate][i] * mat2->mat[i][rowcoordinate];
            }
            result->matof[linecoordinate][rowcoordinate] = true;
            t++;
            result->matofmut[linecoordinate][rowcoordinate].unlock();
        }
        else
        {
            t++;
        }
        linecoordinate = (t + result->numberofrows - 1) / result->numberofrows - 1;
        rowcoordinate = (t - 1) % result->numberofrows;
    }
    result->done = true;
}
int main()
{
    cout << "enter the number of lines of first matrix" << endl;
    int lines;
    cin >> lines;
    cout << "enter the number of rows of first matrix" << endl;
    int rows;
    cin >> rows;
    matrix* mat1 = new matrix(lines, rows);

    cout << "enter elements of first matrix" << endl;
    for (int i = 0; i < mat1->numberoflines; i++)
    {
        for (int y = 0; y < mat1->numberofrows; y++)
        {
            cin >> mat1->mat[i][y];
        }
    }


    cout << "enter the number of lines of second matrix" << endl;
    cin >> lines;
    cout << "enter the number of rows of second matrix" << endl;
    cin >> rows;
    matrix* mat2 = new matrix(lines, rows);

    cout << "enter elements of second matrix" << endl;
    for (int i = 0; i < mat2->numberoflines; i++)
    {
        for (int y = 0; y < mat2->numberofrows; y++)
        {
            cin >> mat2->mat[i][y];
        }
    }

    if (mat1->numberofrows != mat2->numberoflines) {
        cout << "impossible to multiply this matrixes.";
        return 0;
    }
    matrix* result = new matrix(mat1->numberofrows, mat2->numberoflines);
    int numberofthreads;
    cin >> numberofthreads;
    boost::thread_group gr;
    for (int i = 1; i <= numberofthreads; i++)
    {
        gr.create_thread(boost::bind(worker, result, mat1, mat2, i));
    }
    gr.join_all();
    ofstream out("protocolfile.txt");
    cout << "end of calculating";
    for (int i = 0; i < result->numberoflines; i++)
    {
        for (int y = 0; y < result->numberofrows; y++)
        {
            out << setw(4) << result->mat[i][y] << " ";
        }
        out << endl;
    }
    out.close();
    return 0;
}
