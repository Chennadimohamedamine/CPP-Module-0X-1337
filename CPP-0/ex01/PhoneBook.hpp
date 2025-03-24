#pragma once

#include "utils.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
        void display();
        ~PhoneBook();
};