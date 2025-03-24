# pragma once

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        void setname(std::string value);
        void announce(void);
        ~Zombie(void);
};
