#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Default constructor WrongAnimal is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) {
    std::cout << "Parametric constructor WrongAnimal is called" << std::endl;
    this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
    std::cout << "Copy constructor WrongAnimal is called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
    std::cout << "Copy assignment operator WrongAnimal is called" << std::endl;
    if (this != &wrongAnimal) {
        this->type = wrongAnimal.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal Sound" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor WrongAnimal is called" << std::endl;
}
