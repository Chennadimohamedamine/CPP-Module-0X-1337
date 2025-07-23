#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool issigned;
        const int gradesign;
        const int gradeexecute;

    public:
        class GradeTooHighException : public std::exception
        {
        public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
        public:
            const char *what() const throw();
        };
        Form(std::string nm, int gs, int ge);
        Form(const Form &form);
        Form &operator=(const Form &form);
        void beSigned(Bureaucrat &b);
        void signForm(Form &f);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void setIsSigned(bool value);
        ~Form();
};
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif