#include "ClapTrap.hpp"

int main(){
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3 = claptrap;
    claptrap.attack("enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);

    ClapTrap robot("CT-01");
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(8);
    robot.attack("Enemy");
    return 0;
}