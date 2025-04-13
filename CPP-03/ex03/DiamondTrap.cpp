#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string nm) : ClapTrap(nm + "_clap_name"), ScavTrap(nm), FragTrap(nm), name(nm)
{
    hit_points = FragTrap::hit_points;
    attack_damage = FragTrap::attack_damage;
    energy_points = ScavTrap::energy_points;
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &clap)
    : ClapTrap(clap), ScavTrap(clap), FragTrap(clap)
{
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
    *this = clap;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &clap){
    std::cout << "Copy assignment operator DiamondTrap called" << std::endl;
    this->attack_damage = clap.attack_damage;
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "the ClapTrap name is "<< ClapTrap::name <<" and the DiamondTrap is "<< this->name<<" :)" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "destructor DiamondTrap is called " << std::endl;
}