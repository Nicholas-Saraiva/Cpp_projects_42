#pragma once
#include <string>
#include "ICharacter.hpp"

#define MAXSLOTS 4

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria*	_inventory[MAXSLOTS];
public:
	Character();
	Character(std::string const & name);
	Character(const Character& other);

	Character&	operator=(const Character& other);
	
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, Character& target);
	std::string const & Character::getName() const;
	virtual 	~Character();
};