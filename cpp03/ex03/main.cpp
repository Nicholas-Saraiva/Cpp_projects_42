#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- 1. CONSTRUCTION PHASE ---" << std::endl;
	DiamondTrap dt("DUKE");

	std::cout << "\n--- 2. IDENTITY TEST ---" << std::endl;
	dt.whoAmI();

	std::cout << "\n--- 3. ATTACK TEST (ScavTrap Logic) ---" << std::endl;
	dt.attack("a training dummy");
	
	std::cout << "\n--- 4. SPECIAL ABILITIES ---" << std::endl;
	dt.guardGate();
	dt.highFivesGuys();

	std::cout << "\n--- 5. DEEP COPY / ASSIGNMENT TEST ---" << std::endl;
	DiamondTrap copy(dt);
	DiamondTrap assigned;
	assigned = dt;

	std::cout << "Original name: "; dt.whoAmI();
	std::cout << "Copy name:     "; copy.whoAmI();
	std::cout << "Assigned name: "; assigned.whoAmI();

	std::cout << "\n--- 6. DESTRUCTION PHASE ---" << std::endl;
	return 0;
}