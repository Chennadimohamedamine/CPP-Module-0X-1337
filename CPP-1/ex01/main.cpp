#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main()
{
    int n = 5;
    Zombie *zombie = zombieHorde(n, "zombie");
    for (int i = 0; i < n; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0; 
}