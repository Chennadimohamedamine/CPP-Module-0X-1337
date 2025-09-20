#include "RPN.hpp"


PRN::PRN(char *arg):line(arg){
}

int PRN::RunOperation()
{
    std::stringstream ss(line);
    std::string token;
    int value;
    while (std::getline(ss, token, ' ')){
        if (token.find_first_not_of("-+/*0123456789") == std::string::npos)
        {
            if (token.find_first_not_of("0123456789") == std::string::npos)
            {
                value = std::atoi(token.c_str());
                tokens.push(value);
            }else if (token.find_first_not_of("-+/*") == std::string::npos)
            {
                if (tokens.size() < 2)
                    return 1;
                int first,second, result = 0;
                first  = tokens.top(); tokens.pop();
                second = tokens.top(); tokens.pop();
                if (token == "+")
                    result =  second + first;
                if (token == "-")
                    result = second - first;
                if (token == "/")
                {
                    if (first == 0)
                        return 1;
                    result = second / first;
                }
                if (token == "*")
                    result = second * first;
                tokens.push(result);
            }   
        }else
            return 1;
    }
    if (tokens.size() > 1)
        return 1;
    std::cout << tokens.top() << std::endl;
    return 0;
}
PRN::~PRN(){}