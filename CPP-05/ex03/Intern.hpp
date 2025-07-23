#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    static AForm* createShrubbery(std::string const &target);
    static AForm* createRobotomy(std::string const &target);
    static AForm* createPresidential(std::string const &target);

    AForm* makeForm(const std::string &name, const std::string &target);
};

#endif
