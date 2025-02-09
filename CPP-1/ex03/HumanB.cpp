#include "HumanB.hpp"

HumanB::HumanB(std::string n):name(n){}

void HumanB::setWeapon(Weapon w){
    weap = &w;
}
void HumanB::attack(){
    std::cout<< name <<"attacks with their"<<weap->getType()<<std::endl;
}

HumanB::~HumanB(){}