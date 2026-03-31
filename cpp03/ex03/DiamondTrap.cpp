#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "|| A default DiamondTrap was Created!" << std::endl;
	ClapTrap::_printStats();
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "__clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "|| DiamondTrap " << CYAN << name << RESET << " was Created!" << std::endl;
	ClapTrap::_printStats();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
{
	*this = other;
	std::cout << "|| DiamondTrap Copy Constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);	
		std::cout << "DiamondTrap " << _name << " assigned!" << std::endl;		
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is being scrapped!" << std::endl;
}