#pragma once

#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    public:
        ClapTrap(std::string nm);
        ClapTrap(ClapTrap const &clap);
        ClapTrap &operator=(ClapTrap const &clap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};