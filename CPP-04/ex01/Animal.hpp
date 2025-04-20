#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string nm);
        Animal(const Animal &animal);
        virtual void makeSound() const;
        virtual std::string getType() const;
        Animal &operator=(Animal &animal);
        virtual ~Animal();
};