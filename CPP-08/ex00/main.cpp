#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    int find = 10;
    int index = easyfind(v, find);
    if (index != -1)
        std::cout << "Found value: " << v[index] << std::endl;
    else
        std::cout << "the index " <<  find << " is not Found "<< std::endl;

    return 0;
}