#pragma once

#include "ScavTrap.hpp"
#include "./ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap(std::string nm);
        DiamondTrap(DiamondTrap const &trap);
        DiamondTrap &operator=(DiamondTrap const &trap);
        virtual void attack(const std::string& target);
        void whoAmI();
        ~DiamondTrap();
};