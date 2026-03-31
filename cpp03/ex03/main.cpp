#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. INITIALIZATION TESTS ---" << std::endl;
    FragTrap a("Megamen");
    FragTrap b("Zero");

    std::cout << "\n--- 2. COPY CONSTRUCTOR TEST ---" << std::endl;
    FragTrap c(a); 
    std::cout << "\n--- 3. ASSIGNMENT OPERATOR TEST ---" << std::endl;
    a = b;  
    std::cout << "\n--- 4. INDEPENDENCE TEST ---" << std::endl;
    std::cout << "Damaging 'a' (the assigned version of Megamen)..." << std::endl;
    a.takeDamage(30);
    std::cout << "Showing 'b' (the original Zero) - should still have 100 HP:" << std::endl;
    b.attack("nothing");
    std::cout << "Showing 'c' (the copy of Megamen) - should still have 100 HP:" << std::endl;
    c.attack("nothing");
    std::cout << "\n--- 5. UNIQUE FragTrap ACTION ---" << std::endl;
    a.highFivesGuys();
    std::cout << "\n--- 6. DESTRUCTION PHASE ---" << std::endl;
    return 0;
}