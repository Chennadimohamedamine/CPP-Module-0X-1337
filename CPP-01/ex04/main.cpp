#include <iostream>
#include <fstream>
#include <string>


void read_lines(std::ifstream &file, std::ofstream &newfile, const std::string &s1, const std::string &s2)
{
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) // Find all occurrences
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        newfile << line << std::endl;
    }
}

int main(int ac, char **av)
{
    std::string filename;
    std::string s1;
    std::string s2;
    
    if (ac != 4)
    {
        std::cerr << "Usage: ./ex04 [filename] [string2] [string3]" << std::endl;
        return 1;
    }
    filename = av[1];
    if (filename.empty())
    {
        std::cout << "this argument can not be empty" << std::endl;
        return 1;
    }
    s1 = av[2];
    s2 = av[3];
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }
    std::ofstream newfile((filename + ".replace").c_str());
    if (!newfile)
    {
        std::cout << "Error: could not open file" << std::endl;
        file.close();
        return 1;
    }
    read_lines(file, newfile, s1, s2);
    file.close();
    newfile.close();
    return 0;
}