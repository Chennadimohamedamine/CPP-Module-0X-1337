#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Dog:public Animal{

    private:
        Brain *att;
    public:
        Dog();
        Dog(const Dog &dog);
        Dog &operator=(Dog const  &dog);
        void makeSound() const;
        std::string getType() const;
        ~Dog();
};