#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. INITIALIZATION TESTS ---" << std::endl;
    DiamondTrap a("Megamen");
	a.printStats();
    DiamondTrap b("Robotnick");
	b.printStats();
	
    std::cout << "\n--- 2. COPY CONSTRUCTOR TEST ---" << std::endl;
    DiamondTrap c(a); 
    std::cout << "\n--- 3. ASSIGNMENT OPERATOR TEST ---" << std::endl;
    a = b;  
    std::cout << "\n--- 4. INDEPENDENCE TEST ---" << std::endl;
    std::cout << "a.takeDamage(30)" << std::endl;
    a.attack("You");
    a.printStats();
    std::cout << "Showing 'b' still have 100 HP:" << std::endl;
    b.printStats();
    std::cout << "Showing 'c' still have 100 HP:" << std::endl;
    c.printStats();
    std::cout << "\n--- 5. UNIQUE DiamondTrap ACTION ---" << std::endl;
    c.highFivesGuys();
    c.guardGate();
    c.whoAmI();
    std::cout << "\n--- 6. DESTRUCTION PHASE ---" << std::endl;
    ClapTrap    *z = new FragTrap("oi");
	delete z;
	return 0;
}