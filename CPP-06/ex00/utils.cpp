#include <iostream>
#include <string>
#include <sstream>

int count(std::string st, char c)
{
    int count = 0;
    for (size_t i = 0; i < st.length(); i++)
    {
        if (st[i] == c)
            count++;
    }
    return count;
}


int defineType(std::string str)
{
    if (str == "+nan" || str == "-nan" || str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        return 3;
    else if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return 4;
    if (str.length() == 1)
        return 0;
    else if (str.find_first_not_of("-+0123456789") == std::string::npos)
    {
        size_t cplus = count(str, '-');
        size_t cmins = count(str, '+');
        if (cplus > 1 || cmins > 1)
            return -1;
        return 1;
    }
    else if (str.find_first_not_of("-+0123456789f.") == std::string::npos)
    {
        size_t fcount = count(str, 'f');
        size_t dcount = count(str, '.');
        size_t cplus = count(str, '-');
        size_t cmins = count(str, '+');
        if (fcount > 1 || dcount != 1 || cplus > 1 || cmins > 1)
            return -1;
        return 2;
    }
    return -1;
}

int convertTypeOne(std::string st)
{
    int n;
    if (st.find_first_not_of("0123456789") == std::string::npos)
    {
        n = std::atoi(st.c_str());
        if (n >= 0 && n <= 31)
            std::cout << "char: Non displayable\n";
        else if (n > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: '" << static_cast<char>(n) << std::endl;
        std::cout << "int: " << n << "\n"
                  << "float: " << static_cast<float>(n) << ".0f\n"
                  << "double: " << static_cast<double>(n) << ".0" << std::endl;
    }
    else
    {
        n = static_cast<int>(st[0]);
        if (n >= 0 && n <= 31)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << st[0] << "'\n";
        std::cout << "int: " << n << "\n"
                  << "float: " << static_cast<float>(n) << ".0f\n"
                  << "double: " << static_cast<double>(n) << ".0" << std::endl;
    }
    return 0;
}
int convertTypeTow(std::string st)
{
    for (size_t i = 0; i < st.length(); i++)
    {
        if (i != 0 && (st[i] == '+' || st[i] == '-'))
            return -1;
    }
    int n = std::atoi(st.c_str());
    if (n >= 0 && n <= 31)
        std::cout << "char: Non displayable\n";
    else if (n < 0 || n > 127)
        std::cout << "char: impossible\n";
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    std::cout << "int: " << n << "\n"
              << "float: " << static_cast<float>(n) << ".0f\n"
              << "double: " << static_cast<double>(n) << ".0" << std::endl;
    return 0;
}
int convertTypeTree(std::string st)
{
    size_t pos = st.find('f');
    if (pos != std::string::npos && pos != st.length() - 1)
        return -1;
    pos = st.find('.');
    if (st[0] == '.' || st[pos + 1] == 0 || st.length() < 3)
        return -1;
    if (!std::isdigit(st[pos - 1]) || (!std::isdigit(st[pos + 1]) && st[pos + 1] != 'f'))
        return -1;
    for (size_t i = 0; i < st.length(); i++)
    {
        if (i != 0 && (st[i] == '+' || st[i] == '-'))
            return -1;
    }
    bool isfloat = st[st.length() - 1] == 'f';
    int n;
    float f;
    if (isfloat)
        st.erase(st.size() - 1);
    std::istringstream iss(st);
    iss >> f;
    n = static_cast<int>(f);
    if (n >= 0 && n <= 31)
        std::cout << "char: Non displayable\n";
    else if (n < 0 || n > 127)
        std::cout << "char: impossible\n";
    else
        std::cout << "char: '" << static_cast<char>(n) << "'"<< std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << st << "f\n"
                  << "double: " << st << std::endl;
    return 0;
}