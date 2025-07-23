
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Declaration", 75, 25);
        bob.signForm(taxForm);        
        Bureaucrat joe("Joe", 100);
        Form topSecret("Secret File", 50, 10);
        joe.signForm(topSecret); 
        Bureaucrat amine("amine", -1);
    } catch (const std::exception &e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}