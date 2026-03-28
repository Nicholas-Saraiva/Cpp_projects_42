#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

void ClapTrap::_printStats(void) {
    std::cout << WHITE << "|| " << RESET;
    std::cout << "HP: " << std::left << std::setw(8) << _hitPoints;
    std::cout << "EP: " << std::left << std::setw(8) << _energy;
    std::cout << "ATK: " << std::left << std::setw(6) << _attack << std::endl;
}

ClapTrap::ClapTrap() 
	: _name(NULL), _hitPoints(10), _energy(10), _attack(0) {}

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energy(10), _attack(0) {}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_attack = other._attack;
	this->_energy = other._energy;
	this->_hitPoints = other._hitPoints;
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
		<<" cannot take action" << std::endl;
	}
	_printStats();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "|| ClapTrap <" << CYAN << this->_name << RESET << ">" << RED <<" takes "<< RESET << "<" << amount << "> \
points of damage!" << std::endl;
	_printStats();
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
		<<" cannot take action" << std::endl;
	}
	_printStats();
}

ClapTrap::~ClapTrap()
{
}
