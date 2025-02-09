#pragma once

#include "Contact.hpp"
#include <cstdlib>

bool        parcinput(std::string input, int flag);
bool        isdigit(std::string str);
std::string readinput(int flag);
int         ft_atoi(std::string str);
void        displaycontacts(Contact contact, int index);