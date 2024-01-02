#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
struct st
{
    bool isoperated;
    int StartNumber;
    int JumpNumber;
    std::string name;
    double res;
    st();
};
double doing(int a, std::vector<double>& vect);
bool chek(std::string name);