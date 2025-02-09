#include "PhoneBook.hpp"

int PhoneBook::index = 0;

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::string input = readinput(i);
        if (parcinput(input, i))
            i--;
        else
            contacts[index % 8].setvalue(input, i);
    }
    index++;
}

void PhoneBook::searchContact()
{
    if (index == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return;
    }
    std::cout << "------------------------------------------|" << std::endl;
    std::cout << "index    |first name|lastname  |nickname  |" << std::endl;
    std::cout << "------------------------------------------|" << std::endl;
    display();
    std::string input;
    int in;
    input = readinput(5);
    in = ft_atoi(input);
    if (in >= 0 && in < 8)
    {
        if (index != 8 && in >= index)
            std::cout << "No contacts available" << std::endl;
        else
        {
            std::cout << "First Name     : " << contacts[in].getvalue(0) << std::endl;
            std::cout << "Last Name      : " << contacts[in].getvalue(1) << std::endl;
            std::cout << "Nickname       : " << contacts[in].getvalue(2) << std::endl;
            std::cout << "Phone Number   : " << contacts[in].getvalue(3) << std::endl;
            std::cout << "Darkest Secret : " << contacts[in].getvalue(4) << std::endl;
        }
    }
    else
        std::cout << "Invalid index" << std::endl;
}
void PhoneBook::display()
{
    if (index <= 7)
    {
        for (int i = 0; i < index; i++)
            displaycontacts(contacts[i], i);
    }
    else
    {
        for (int i = 0; i < 8; i++)
            displaycontacts(contacts[i], i);
    }
}