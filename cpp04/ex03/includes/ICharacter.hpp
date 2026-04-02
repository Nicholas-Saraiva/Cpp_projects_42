#pragma once
#include <string>
#include "AMateria.hpp"

#define MAXSLOTS 4

class ICharacter
{
private:
	std::string	_name;
	AMateria*	slots[MAXSLOTS];
public:
	ICharacter();
	ICharacter(const ICharacter& other);
	ICharacter&	operator=(const ICharacter& other);
	virtual ~ICharacter();
	virtual std::string const &	getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& targer) = 0;
};