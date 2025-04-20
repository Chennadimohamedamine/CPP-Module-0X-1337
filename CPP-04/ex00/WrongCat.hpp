#pragma once

#include "./WrongAnimal.hpp"

class WrongCat:public WrongAnimal{

    public:
        WrongCat();
        WrongCat(const WrongCat &wrongCat);
        WrongCat &operator=(WrongCat const &wrongCat);
        void makeSound() const;
        ~WrongCat();
};