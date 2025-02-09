#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string cname)
{
    name = cname;
}
Zombie::~Zombie(void)
{
    std::cout << "destroyed " << name << std::endl;
}

void Zombie::announce(void)
{
    std::cout  << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
