#include "Zombie.hpp"

Zombie::Zombie(){}

void Zombie::setname(std::string value)
{
    name = value;
}
Zombie::~Zombie(void)
{
    std::cout << "constarct is destroyed" << name <<std::endl;
}

void Zombie::announce(void)
{
    std::cout  << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
