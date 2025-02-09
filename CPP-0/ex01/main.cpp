#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;
    while (true)
    {
        std::cout<<"enter you command : ";
        std::getline(std::cin, input);
        if(std::cin.eof())
            return 1;
        else if (input == "ADD" || input == "add")
            phonebook.addContact();
        else if(input == "SEARCH" || input == "search")
            phonebook.searchContact();
        else if (input == "EXIT" || input == "exit")
            return 0;
        else
            std::cout<< "plz enter right command [ADD , SEARCH, EXIT]" << std::endl;
    }
    return 0;
}