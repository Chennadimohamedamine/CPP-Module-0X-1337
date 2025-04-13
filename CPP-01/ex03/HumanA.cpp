#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w):name(n), weap(w){}

void HumanA::attack(){
    std::cout<< name <<" attacks with their "<<weap.getType()<<std::endl;
}
HumanA::~HumanA(){}