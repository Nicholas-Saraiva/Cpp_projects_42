#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::printStats(void) 
{
	std::cout << WHITE << "|| " << RESET;
	std::cout <<  CYAN << _name << " Stats > " << RESET;
	std::cout << "||HP: " << _hitPoints;
	std::cout << "||EP: " << _energy;
	std::cout << "||ATK: "<< _attack << std::endl;
}

ClapTrap::ClapTrap() 
	: _name(NULL), _hitPoints(10), _energy(10), _attack(0) 
{
	std::cout << "|| A default ClapTrap was Created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energy(10), _attack(0)
{
	std::cout << "|| ClapTrap " << CYAN << name << RESET << " was Created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "|| ClapTrap Copy Constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_attack = other._attack;
	this->_energy = other._energy;
	this->_hitPoints = other._hitPoints;
	std::cout << "|| ClapTrap " << _name << " assigned!" << std::endl;		
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		_energy--;
		std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << RED <<" attacks "
		<< RESET << "<" << GREEN << target << RESET << ">, causing "
		<< "<" << this->_attack << "> points of damage!" << std::endl;
	}
	else
	{
		std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << RED <<" takes "<< RESET << "<" << amount << "> \
points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
	if (_energy > 0 && _hitPoints > 0)
	{
		if (amount <= 100 && this->_hitPoints + amount <= 100)
			this->_hitPoints += amount;
		else
			this->_hitPoints = 100;
		_energy--;		
		std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << GREEN <<" Repairs "<< RESET << "<" 
		<< amount << "> points of life!" << std::endl;
	}
	else
	{
		std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << RESET << std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " rust away >:(" << std::endl;
}
