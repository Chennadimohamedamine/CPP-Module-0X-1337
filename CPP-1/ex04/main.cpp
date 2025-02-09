#include "util.hpp"

int main(int ac, char **av)
{
    std::string filename;
    std::string s1;
    std::string s2;
    
    if (ac != 4)
    {
        std::cerr << "Usage: ./ex04 [string1] [string2] [string3]" << std::endl;
        return 1;
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    std::ifstream file(filename);
    std::ofstream newfile(filename + ".replace");
    if (!file || !newfile)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    if (read_lines(newfile, file, s1, s2))
    {
        std::cerr << "Error: could not read lines" << std::endl;
        file.close();
        newfile.close();
        return 1;
    }
    file.close();
    newfile.close();
    return 0;
}