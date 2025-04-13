#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nm):name(nm),hit_points(10),energy_points(10),attack_damage(0){
    std::cout << "Default ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &clap)
{
    std::cout << "Copy constructor ClapTrap called" << std::endl;
    *this = clap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clap){
    std::cout << "Copy assignment operator ClapTrap called" << std::endl;
    this->attack_damage = clap.attack_damage;
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    return (*this);
}

void ClapTrap::attack(const std::string& target){
    if (this->energy_points == 0 || this->energy_points == 0) {
            std::cout << "ClapTrap " << name << " can't attack!" << std::endl;
            return;
        }
    this->energy_points -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "  << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hit_points == 0) {
            std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
            return;
        }
    this->hit_points = (amount >= this->hit_points) ? 0 : this->hit_points - amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hit_points == 0 || this->energy_points == 0) {
            std::cout << "ClapTrap " << name << " can't repair itself!" << std::endl;
            return;
        }
    this->hit_points += amount;
        this->energy_points--;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "destructor  ClapTrap is called " << std::endl;
}