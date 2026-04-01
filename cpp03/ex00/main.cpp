#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a("Megamen");
    a.printStats();

    a.attack("Robotnik");
    a.takeDamage(9);
    a.printStats();
    a.beRepaired(3);
    a.printStats();
    a.attack("Robotnik");
    a.takeDamage(5);
    a.printStats();
    a.beRepaired(3);
    a.attack("Robotnik");
    return 0;
}