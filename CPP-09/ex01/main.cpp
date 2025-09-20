#include "RPN.hpp"

int main(int ac, char **av)
{
    int retu = 0;
    if (ac == 2)
    {
        PRN calcul(av[1]);
        retu = calcul.RunOperation();
    }else
        retu = 1;
    if (retu == 1)
        std::cerr << "Error" << std::endl;
    return retu;
}