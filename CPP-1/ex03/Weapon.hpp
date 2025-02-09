#pragma once

#include <iostream>
#include <string>


class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string newtype);
        const std::string& getType();
        void setType(std::string newtype);

        ~Weapon();
};
