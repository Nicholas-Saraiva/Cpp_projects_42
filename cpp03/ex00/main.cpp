#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a("Megamen");

    a.attack("Robotnik");
    a.takeDamage(9);
    a.beRepaired(3);
    a.attack("Robotnik");
    a.takeDamage(5);
    a.beRepaired(3);
    a.attack("Robotnik");
    return 0;
}