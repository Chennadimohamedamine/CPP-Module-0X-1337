# pragma once

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        void announce(void);
        ~Zombie(void);
};