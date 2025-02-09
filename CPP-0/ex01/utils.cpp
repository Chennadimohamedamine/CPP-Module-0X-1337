#include "PhoneBook.hpp"

bool isdigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool parcinput(std::string input, int flag)
{
    if (input.empty())
    {
        std::cout << "Invalid input: it must not be empty." << std::endl;
        return true;
    }
    else if (flag == 3 && !isdigit(input))
    {
        std::cout << "Invalid input: it must contain only numbers." << std::endl;
        return true;
    }
    return false;
}
std::string readinput(int flag)
{
    std::string input;
    if (flag == 0)
        std::cout << "Enter First Name: ";
    else if (flag == 1)
        std::cout << "Enter Last Name: ";
    else if (flag == 2)
        std::cout << "Enter Nickname: ";
    else if (flag == 3)
        std::cout << "Enter Phone Number: ";
    else if (flag == 4)
        std::cout << "Enter Darkest Secret: ";
    else if (flag == 5)
        std::cout << "Enter an index from 0 to 7 : ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << "\nInput error EOF detected. Exiting..." << std::endl;
        exit(0);
    }
    return input;
}

int ft_atoi(std::string str)
{
    long r;
    int i;

    i = 0;
    if (str[i] == '+')
        i++;
    r = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - 48);
        i++;
    }
    return (r);
}
void displaycontacts(Contact contact, int index)
{
    std::cout << index << "        |";
    for (int i = 0; i < 3; i++)
    {
        if (contact.getvalue(i).length() > 10)
            std::cout << contact.getvalue(i).substr(0, 9) << ".|";
        else
        {
            int c = 10 - contact.getvalue(i).length();
            std::cout << contact.getvalue(i);
            for (int j = 0; j < c; j++)
                std::cout << " ";
            std::cout << "|";
        }
    }
    std::cout << std::endl;
}