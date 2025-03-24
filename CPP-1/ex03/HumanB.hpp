#pragma once
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weap;
    public:
        HumanB(std::string n);
        void setWeapon(Weapon &w);
        void attack();
        ~HumanB();
};

