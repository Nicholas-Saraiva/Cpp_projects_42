#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. INITIALIZATION TESTS ---" << std::endl;
    ScavTrap a("Megamen");
    ScavTrap b("Robotnick");

    std::cout << "\n--- 2. COPY CONSTRUCTOR TEST ---" << std::endl;
    ScavTrap c(a); 
    std::cout << "\n--- 3. ASSIGNMENT OPERATOR TEST ---" << std::endl;
    a = b;  
    std::cout << "\n--- 4. INDEPENDENCE TEST ---" << std::endl;
    std::cout << "a.takeDamage(30)" << std::endl;
    a.takeDamage(30);
    a.printStats();
    std::cout << "Showing 'b' still have 100 HP:" << std::endl;
    b.printStats();
    std::cout << "Showing 'c' still have 100 HP:" << std::endl;
    c.printStats();
    std::cout << "\n--- 5. UNIQUE SCAVTRAP ACTION ---" << std::endl;
    c.guardGate();
    c.guardGate();
    std::cout << "\n--- 6. DESTRUCTION PHASE ---" << std::endl;
    return 0;
}