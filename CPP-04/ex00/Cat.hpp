#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {

public:
    Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    ~Cat();

    void makeSound() const;
    std::string getType() const;
};

#endif
