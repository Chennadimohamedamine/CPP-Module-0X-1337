#include "./FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name){
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &clap):ClapTrap(clap)
{
    std::cout << "Copy constructor FragTrap called" << std::endl;
    *this = clap;
}

FragTrap &FragTrap::operator=(FragTrap const &clap){
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
    this->attack_damage = clap.attack_damage;
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    return (*this);
}
void FragTrap::attack(const std::string& target){
    if (this->energy_points == 0 || this->energy_points == 0) {
            std::cout << "FragTrap " << name << " can't attack!" << std::endl;
            return;
        }
    this->energy_points -= 1;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "  << this->attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "positive high-fives request " << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "destructor FragTrap is called" << std::endl;
}