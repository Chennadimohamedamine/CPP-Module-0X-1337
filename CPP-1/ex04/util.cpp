#include "util.hpp"

void ft_replace(std::string &s, std::string s1, std::string s2)
{
    size_t pos = 0;
    while ((pos = s.find(s1, pos)) != std::string::npos)
    {
        s.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}
bool read_lines(std::ifstream &f1, std::ifstream f2,std::string s1, std::string s2)
{
    std::string line;
    while (std::getline(f2, line))
    {
        size_t pos = 0;
        if ((pos = line.find(s1)) != std::string::npos)
        {
            line = ft_replace(line, s1, s2);
            f1 << s2 << std::endl;
            continue;
        }
        f1 << line << std::endl;
    }
    return false;
}
