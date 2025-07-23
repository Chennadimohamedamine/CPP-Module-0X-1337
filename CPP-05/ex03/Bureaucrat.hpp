#pragma once

#include <iostream>
#include "AForm.hpp"
#include <stdexcept>

class AForm;

class Bureaucrat{
    private:
        const std::string  name;
        int grade;
    public:
        class GradeTooHighException : public std::exception
        {
            public:
             const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
             const char *what() const throw();
        };
        Bureaucrat(std::string nm, int gd);
        Bureaucrat(const Bureaucrat &bureaucrat);
        void setGrade(int gr);
        std::string getName() const;
        int getGrade() const;

        void signForm(AForm &f);
        void increment();
        void decrement();
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);