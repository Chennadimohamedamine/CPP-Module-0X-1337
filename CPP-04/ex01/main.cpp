#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{
    const int size = 20;
    const Animal *animal[size];

    for(int i = 0; i < size / 2; i++)
        animal[i] = new Dog();

    for(int i = size / 2 ; i < size; i++)
        animal[i] = new Cat();
    
    for(int i = 0; i < size; i++)
        animal[i]->makeSound();
    
    for(int i = 0; i < size; i++)
         delete animal[i];
    return 0;
}