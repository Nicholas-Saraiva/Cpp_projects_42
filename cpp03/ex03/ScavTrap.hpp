#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	int		_isGuardingGate;
	void	_printStats(void);
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);

	ScavTrap&	operator=(const ScavTrap& other);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		guardGate();
	~ScavTrap();
};