#include "./Cat.hpp"


Cat::Cat():Animal("Cat"){
    std::cout << "Default constructor Cat is called" <<std::endl;
}
Cat::Cat(const Cat &cat):Animal(cat)
{
    std::cout << "Copy constructor Cat is called" <<std::endl;
    *this = cat;
}
Cat& Cat::operator=(const Cat& cat) {
    std::cout << "Copy assignment operator Cat is called" << std::endl;
    if (this != &cat) {
        this->type = cat.type;
    }
    return *this;
}

std::string Cat::getType() const
{
    return (this->type);
}
void Cat::makeSound() const
{
    std::cout << "MAW MAW"<< std::endl;
}

Cat::~Cat(){
    std::cout << "Destructor Cat is called" << std::endl;
}