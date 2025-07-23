#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;

        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm *roboForm = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *presForm = someRandomIntern.makeForm("presidential pardon", "Amine");
        AForm *unknownForm = someRandomIntern.makeForm("nuclear launch", "World");
        Bureaucrat bob("Bob", 5);

        if (shrubForm)
        {
            shrubForm->beSigned(bob);
            shrubForm->execute(bob);
            delete shrubForm;
        }

        if (roboForm)
        {
            roboForm->beSigned(bob);
            roboForm->execute(bob);
            delete roboForm;
        }

        if (presForm)
        {
            presForm->beSigned(bob);
            presForm->execute(bob);
            delete presForm;
        }

        if (unknownForm)
            delete unknownForm;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
