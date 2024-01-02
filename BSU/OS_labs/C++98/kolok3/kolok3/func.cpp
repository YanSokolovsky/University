#include "func.h"
st::st()
{
    isoperated = false;
    StartNumber = 0;
    JumpNumber = 0;
    name = "name";
    res = 0.0;
}
double doing(int a, std::vector<double>& vect)
{
    double res;
    switch (a)
    {
    case 1:
        res = 0.0;
        for (int i = 0; i < vect.size(); i++)
        {
            res += vect[i];
        }
        return res;
    case 2:
        res = 1.0;
        for (int i = 0; i < vect.size(); i++)
        {
            res *= vect[i];
        }
        return res;
    case 3:
        res = 0.0;
        for (int i = 0; i < vect.size(); i++)
        {
            res += vect[i] * vect[i];
        }
        return res;
    default:
        break;
    }
    return 0;
};
bool chek(std::string name)
{
    std::ifstream m;
    m.open(name);
    if (m.is_open())
    {
        m.close();
        return true;
    }
    m.close();
    return false;
};