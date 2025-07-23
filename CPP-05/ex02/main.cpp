#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("human");
    PresidentialPardonForm pardon("criminal");

    shrub.beSigned(boss);
    shrub.execute(boss);

    robot.beSigned(boss);
    robot.execute(boss);

    pardon.beSigned(boss);
    pardon.execute(boss);
}
