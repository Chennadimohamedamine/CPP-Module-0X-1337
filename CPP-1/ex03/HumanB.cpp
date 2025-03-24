#include "HumanB.hpp"

HumanB::HumanB(std::string n):name(n){
    weap = NULL;
}

void HumanB::setWeapon(Weapon &w){
    weap = &w;
}
void HumanB::attack(){
    if (weap == NULL)
        std::cout<< name <<" no weapon has been set!"<<std::endl;
    else
        std::cout<< name <<" attacks with their "<<weap->getType()<<std::endl;
}

HumanB::~HumanB(){}