#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat b1("Ali", 42);
        Bureaucrat b2("Sara", 1);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.increment();
        std::cout << "After increment: " << b1 << std::endl;
        b2.increment();
        b1.decrement();
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
