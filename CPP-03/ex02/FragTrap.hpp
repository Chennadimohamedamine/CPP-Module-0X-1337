#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{

    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &trap);
        FragTrap &operator=(FragTrap const &trap);
        void highFivesGuys(void);
        void attack(const std::string& target);
        ~FragTrap();
};