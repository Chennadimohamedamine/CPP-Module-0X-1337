#include "DiamondTrap.hpp"

int main(){
    DiamondTrap trap("test");
    trap.attack("enemy");
    trap.highFivesGuys();
    trap.whoAmI();

    DiamondTrap robot("CT-01");
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.highFivesGuys();
    trap.whoAmI();
    return 0;
}