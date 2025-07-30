#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main() {
    Base* ptr = generate();

    std::cout << "Using pointer: ";
    identify(ptr);

    std::cout << "Using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}