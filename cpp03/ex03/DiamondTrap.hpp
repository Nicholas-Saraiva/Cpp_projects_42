#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);

	using	ScavTrap::attack;
	void	whoAmI();

	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();
};
