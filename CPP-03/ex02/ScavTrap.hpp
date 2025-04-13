#pragma once

#include "./ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &clap);
        ScavTrap &operator=(ScavTrap const &clap);
        void guardGate();
        void attack(const std::string& target);
        ~ScavTrap(); 
};