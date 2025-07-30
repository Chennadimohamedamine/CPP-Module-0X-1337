#include "ScalarConverte.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            ScalarConverter::convert(str);
        }
    }
    else
        std::cout << "USAGE: ./convert arg ..." << std::endl;
    return 0;
}