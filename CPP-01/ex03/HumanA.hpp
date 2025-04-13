# pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weap;
    public:
        HumanA(std::string n, Weapon &w);
        void attack();
        ~HumanA();
};