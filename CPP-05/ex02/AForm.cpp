#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "highest possible grade";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "lowest possible grade";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed: cannot execute an unsigned form.";
}

AForm::AForm(std::string nm, int gs, int ge) :name(nm), issigned(false) ,gradesign(gs), gradeexecute(ge)
{
    std::cout << "AForm Bureaucrat  constructor called" << std::endl;
}

AForm::AForm(const AForm &Aform): name(Aform.name),
      gradesign(Aform.gradesign), gradeexecute(Aform.gradeexecute)
{
    std::cout << "From Copy constructor called" << std::endl;
    *this = Aform;
}

AForm &AForm::operator=(const AForm &Aform)
{
    this->issigned = Aform.issigned;
    return *this;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= gradesign)
        setIsSigned(true);
    else
        throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << " the name: " << f.getName() << " is signed: " << f.getIsSigned() << " and the grade to signed: " << f.getGradeToSign() << " and the grade to execute: " << f.getGradeToExecute();
    return os;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return issigned;
}

int AForm::getGradeToSign() const
{
    return gradesign;
}

int AForm::getGradeToExecute() const
{
    return gradeexecute;
}
void AForm::setIsSigned(bool value)
{
    issigned = value;
}
AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}