#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try{
        BitcoinExchange btc(ac,av[1]);
    }catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what()<<std::endl;
    }
}