#include "Contact.hpp"

Contact::Contact() {}

void Contact::setvalue(std::string value, int index)
{
    this->var[index] = value;
}
std::string Contact::getvalue(int index)
{
    return this->var[index];
}