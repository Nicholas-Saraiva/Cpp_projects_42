#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class ClapTrap
{
private:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energy;
	unsigned int	_attack;
	void			_printStats();
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);

	ClapTrap&	operator=(const ClapTrap& other);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	~ClapTrap();
};
