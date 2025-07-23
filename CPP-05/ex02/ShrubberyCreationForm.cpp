#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137),target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file(target + "_shrubbery");
    if (file.is_open()) {
        file << "       🌲       \n";
        file << "      🌲🌲🌲      \n";
        file << "     🌲🌲🌲🌲🌲     \n";
        file << "    🌲🌲🌲🌲🌲🌲🌲    \n";
        file << "       |||       \n";
        file.close();
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sh):AForm(sh)
{
    std::cout << "From Copy constructor called" << std::endl;
    *this = sh;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}