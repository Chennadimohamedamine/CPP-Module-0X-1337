#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;
    while (true)
    {
        input = readinput(6);
        if (input == "ADD")
            phonebook.addContact();
        else if(input == "SEARCH")
            phonebook.searchContact();
        else if (input == "EXIT")
            return 0;
        else
            std::cout<< "plz enter right command [ADD , SEARCH, EXIT]" << std::endl;
    }
    return 0;
}