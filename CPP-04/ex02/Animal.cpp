#include "Animal.hpp"


Animal::Animal():type(" << default >>"){
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(std::string nm):type(nm)
{
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const Animal &animal){
    std::cout << "Copy constructor Animal called" << std::endl;
    this->type = animal.type;
}

std::string Animal::getType() const
{
    return (this->type);
}

Animal &Animal::operator=(Animal &animal){
    std::cout << "Copy assignment operator  Animal called" << std::endl;
    if (this != &animal) {
        this->type = animal.type;
    }
    return (*this); 
}

Animal::~Animal()
{
    std::cout << "destructor Animal is called " << std::endl;
}
