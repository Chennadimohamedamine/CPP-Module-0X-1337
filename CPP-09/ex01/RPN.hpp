#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>


class PRN{
    private:
    std::stack<int> tokens;
    std::stack<int> help;
    std::string line;
    public:
        PRN(char *arg);
        ~PRN();
        int RunOperation();
};