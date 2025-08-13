#include "iter.hpp"

int main()
{
    const int arr[] = {1, 85, 21,63,65,74,15,96,32};
    iter(arr, 9, print);
    std::cout << "===================" << std::endl;
    int arr1[] = {1, 85, 21,63,65,74,15,96,32};
    iter(arr1, 9, print);
    return 0;
}