#include "./Dog.hpp"

Dog::Dog() : Animal("Dog") {
    this->att = new Brain();
    std::cout << "Default constructor Dog is called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Copy constructor Dog is called" << std::endl;
    this->att = new Brain(*dog.att);
}

Dog& Dog::operator=(const Dog& dog) {
    std::cout << "Copy assignment operator Dog is called" << std::endl;
    if (this != &dog) {
        this->type = dog.type;
        delete this->att;
        this->att = new Brain(*dog.att);
    }
    return *this;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::makeSound() const {
    std::cout << "Dogs bark" << std::endl;
}

Dog::~Dog() {
    delete this->att;
    std::cout << "Destructor Dog is called" << std::endl;
}
