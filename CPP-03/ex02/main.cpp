#include "./FragTrap.hpp"

int main(){
    FragTrap trap("test");
    trap.attack("enemy");
    trap.highFivesGuys();
    
    FragTrap t2 = trap;
    t2.attack("ghlid");

    FragTrap robot("CT-01");
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.highFivesGuys();
    return 0;
}