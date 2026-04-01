#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 30;
	std::cout << "|| A default DiamondTrap was Created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;

	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 30;
	std::cout << "|| DiamondTrap " << CYAN << name << RESET << " was Created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	std::cout << "|| DiamondTrap Copy Constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);	
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "|| DiamondTrap " << _name << " assigned!" << std::endl;		
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "|| My name is " << this->_name << " in Diamond but " 
	<< ClapTrap::_name << " in ClapTrap." << std::endl;
	std::cout << WHITE << "|| " << RESET;
	std::cout <<  CYAN << _name << " Stats > " << RESET;
	std::cout << "||HP: " << _hitPoints;
	std::cout << "||EP: " << _energy;
	std::cout << "||ATK: "<< _attack << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is being scrapped!" << std::endl;
}