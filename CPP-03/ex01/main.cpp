#include "ScavTrap.hpp"

int main(){
    ScavTrap trap("CT-00");
    ScavTrap tr1 = trap;
    trap.attack("enemy");

    tr1.guardGate();
    trap.ClapTrap::attack("enemy");
    trap.guardGate();
    ScavTrap robot("CT-01");
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.guardGate();
    return 0;
}