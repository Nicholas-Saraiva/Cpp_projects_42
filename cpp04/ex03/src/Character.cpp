#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < MAXSLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < MAXSLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAXSLOTS; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		this->_name = other._name;
	}
	return (*this);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << "|| Equipping material of type: " << m->getType() << std::endl;
			this->_inventory[i] = m;
			return ;
		}
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
		return ;
	std::cout << "|| Unequiping material of type: " << this->_inventory[idx]->getType() << std::endl;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, Character &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < MAXSLOTS; i++)
	{
		if(this->_inventory[i])
			delete _inventory[i];
	}
}
