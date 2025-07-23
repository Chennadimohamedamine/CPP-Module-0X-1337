#include "./Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const  throw()
{
    return "highest possible grade";
}
const char*  Bureaucrat::GradeTooLowException:: what() const  throw()
{
    return "lowest possible grade";
}

Bureaucrat::Bureaucrat(std::string nm, int gd):name(nm)
{
    if (gd < 1)
        throw GradeTooHighException();
    else if (gd > 150)
        throw GradeTooLowException();
    grade = gd;
    std::cout << "Parameter Bureaucrat  constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat){
    std::cout << " Bureaucrat Copy constructor called" << std::endl;
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->grade = bureaucrat.grade;
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    return (*this);
}

void Bureaucrat::signForm(AForm &f)
{
    try{
        f.beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }catch(const std::exception &e)
    {
        std::cout << this->name << " couldn’t sign " << f.getName() << " because  " << e.what() << std::endl;
    }
}
void Bureaucrat::setGrade(int gr)
{
    this -> grade = gr;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}
void Bureaucrat::decrement()
{
    if (this->grade + 1 > 150)
        throw GradeTooHighException();
    this->grade++;
}

void Bureaucrat::increment()
{
    if (this->grade - 1 < 1)
        throw GradeTooLowException();
    this->grade--;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor Bureaucrat called" << std::endl;
}