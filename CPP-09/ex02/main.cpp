#include  "PmergeMe.hpp"


int main(int ac, char **av)
{
    try
    {
        PmergeMe p(ac, av);
        p.startProcessing();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}