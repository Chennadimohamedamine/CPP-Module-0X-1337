#pragma once

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string var[5];
    public:
        Contact();
        void setvalue(std::string value, int index);
        std::string getvalue(int index);
};
