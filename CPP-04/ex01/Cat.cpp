#include "./Cat.hpp"


Cat::Cat():Animal("Cat"){
    this->att = new Brain();
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
        delete this->att;
        this->att = new Brain(*cat.att);
    }
    return *this;
}

std::string Cat::getType() const
{
    return (this->type);
}
void Cat::makeSound() const
{
    std::cout << "Cats meow."<< std::endl;
}

Cat::~Cat(){
    delete this->att;
    std::cout << "Destructor Cat is called" << std::endl;
}