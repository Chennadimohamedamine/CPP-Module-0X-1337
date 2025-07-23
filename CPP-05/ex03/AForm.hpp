#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm
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
        class FormNotSignedException : public std::exception
        {
        public:
            const char *what() const throw();
        };

        AForm(std::string nm, int gs, int ge);
        AForm(const AForm &Aform);
        AForm &operator=(const AForm &Aform);
        
        void beSigned(Bureaucrat &b);
        void signAForm(AForm &f);

        virtual void execute(Bureaucrat const &executor) const = 0;
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void setIsSigned(bool value);
        virtual ~AForm();
};
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif