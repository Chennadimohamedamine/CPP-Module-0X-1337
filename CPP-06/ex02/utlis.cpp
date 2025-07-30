#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    int random = std::rand() % 3;
    if (random == 0)
        return new B();
    else if (random == 1)
        return new C();
    else
        return new A();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try{
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &){
        try{
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &){
            std::cout << "C" << std::endl;
        }
    }
}