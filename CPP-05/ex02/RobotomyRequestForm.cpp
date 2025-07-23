#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45),target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully 🤖" << std::endl;
    else
        std::cout << "The robotomy of " << target << " failed 💥" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &sh):AForm(sh)
{
    std::cout << "From Copy constructor called" << std::endl;
    *this = sh;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}