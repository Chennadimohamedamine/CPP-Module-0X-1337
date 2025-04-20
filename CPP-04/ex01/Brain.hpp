#pragma once

#include <iostream>

class Brain{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(Brain const  &brain);
        ~Brain();
};