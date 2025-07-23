#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy constructor called." << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << "Intern assignment operator called." << std::endl;
    return *this;
}


AForm* Intern::createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(std::string const &) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (name == names[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Intern couldn't find the form: " << name << std::endl;
    return NULL;
}

Intern::~Intern() {
    std::cout << "Intern destructor called." << std::endl;
}