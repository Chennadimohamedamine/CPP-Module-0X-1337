#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "highest possible grade";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "lowest possible grade";
}

Form::Form(std::string nm, int gs, int ge) :name(nm), issigned(false) ,gradesign(gs), gradeexecute(ge)
{
    std::cout << "Form  constructor called" << std::endl;
}

Form::Form(const Form &form): name(form.name),
      gradesign(form.gradesign), gradeexecute(form.gradeexecute)
{
    std::cout << "From Copy constructor called" << std::endl;
    *this = form;
}

Form &Form::operator=(const Form &form)
{
    this->issigned = form.issigned;
    return *this;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= gradesign)
        setIsSigned(true);
    else
        throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << " the name: " << f.getName() << " is signed: " << f.getIsSigned() << " and the grade to signed: " << f.getGradeToSign() << " and the grade to execute: " << f.getGradeToExecute();
    return os;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return issigned;
}

int Form::getGradeToSign() const
{
    return gradesign;
}

int Form::getGradeToExecute() const
{
    return gradeexecute;
}
void Form::setIsSigned(bool value)
{
    issigned = value;
}
Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}