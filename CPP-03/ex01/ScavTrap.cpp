#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name):ClapTrap(name){
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &clap):ClapTrap(clap)
{
    std::cout << "Copy constructor ScavTrap called" << std::endl;
    *this = clap;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &clap){
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    this->attack_damage = clap.attack_damage;
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    return (*this);
}
void ScavTrap::attack(const std::string& target){
    if (this->energy_points == 0 || this->energy_points == 0) {
            std::cout << "ScavTrap " << name << " can't attack!" << std::endl;
            return;
        }
    this->energy_points -= 1;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "  << this->attack_damage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "destructor ScavTrap is called" << std::endl;
}