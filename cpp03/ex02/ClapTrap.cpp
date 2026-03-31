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
	: _name(NULL), _hitPoints(10), _energy(10), _attack(0)
{
	std::cout << "|| A default ClapTrap was Created!" << std::endl;
	_printStats();
}
ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energy(10), _attack(0)
{
	std::cout << "|| A ClapTrap " << CYAN << name << RESET << " was Created!" << std::endl;
	_printStats();
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "|| A ClapTrap was created through copy assignment!" << std::endl;
	_printStats();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "|| \033[35m[SYSTEM]\033[0m " << _name << " data has been cloned!" << std::endl;
	}
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
	std::cout << "|| ClapTrap " << CYAN << this->_name << RESET << " died a horrible death :()" << std::endl;
	_printStats();
}
