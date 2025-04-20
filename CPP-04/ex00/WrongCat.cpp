#include "./WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat"){
    std::cout << "Default constructor WrongCat is called" <<std::endl;
}
WrongCat::WrongCat(const WrongCat &wrongCat):WrongAnimal(wrongCat)
{
    std::cout << "Copy constructor WrongCat is called" <<std::endl;
    *this = wrongCat;
}
WrongCat &WrongCat::operator=(WrongCat const  &wrongCat){
    std::cout << "Copy assignment operator WrongCat is called" <<std::endl;
    if (this != &wrongCat) {
        this->type = wrongCat.type; 
    }
    return (*this);
}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat Sound"<< std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "Destructor WrongCat is called" << std::endl;
}