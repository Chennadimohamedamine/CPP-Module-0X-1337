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
bool isprintble(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isprint(str[i]))
            return false;
    }
    return true;
}

bool is_all_spaces(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c != ' ')
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
    else if (!isprintble(input))
    {
        std::cout << "Invalid input: it must not contain non-printable characters." << std::endl;
        return true;
    }
    else if (is_all_spaces(input))
    {
        std::cout << "Invalid input: it must not contain only spaces." << std::endl;
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
        std::cout << "Enter First Name     : ";
    else if (flag == 1)
        std::cout << "Enter Last Name      : ";
    else if (flag == 2)
        std::cout << "Enter Nickname       : ";
    else if (flag == 3)
        std::cout << "Enter Phone Number   : ";
    else if (flag == 4)
        std::cout << "Enter Darkest Secret : ";
    else if (flag == 5)
        std::cout << "Enter an index from 0 to 7 : ";
    else if (flag == 6)
        std::cout << "Enter your command: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << "\nInput error EOF detected. Exiting..." << std::endl;
        exit(1);
    }
    return input;
}

int ft_atoi(std::string str)
{
    long r = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '+' || str[i] == '-')
        sign = str[i++] == '-' ? -1 : 1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - 48);
        if ((r * sign) > 2147483647 || (r * sign) < 0)
            return -1337;
        i++;
    }
    return (r * sign);
}
void displaycontacts(Contact contact, int index)
{
    std::cout << "        " <<index << "|";
    for (int i = 0; i < 3; i++)
    {
        if (contact.getvalue(i).length() > 10)
            std::cout << contact.getvalue(i).substr(0, 9) << ".|";
        else
        {
            int c = 10 - contact.getvalue(i).length();
            for (int j = 0; j < c; j++)
                std::cout << " ";
            std::cout << contact.getvalue(i) << "|";
        }
    }
    std::cout << std::endl;
}