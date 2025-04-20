#include "./Brain.hpp"

Brain::Brain(){
    std::cout << "Default constructor Brain is called" <<std::endl;
}
Brain::Brain(const Brain &brain)
{   
    std::cout << "Copy constructor Brain is called" <<std::endl;
    *this  = brain;
}
Brain &Brain::operator=(Brain const &brain){
    std::cout << "Copy assignment operator Brain is called" <<std::endl; 

    for(int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}
Brain::~Brain(){
    std::cout << "Destructor Brain is called" << std::endl;
}