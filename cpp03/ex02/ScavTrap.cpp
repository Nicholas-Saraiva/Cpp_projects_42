#include "ScavTrap.hpp"
#include <iostream>
#include <iomanip>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_isGuardingGate = 0;
	std::cout << "|| A default ScavTrap was Created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_isGuardingGate = 0;
	std::cout << "|| ScavTrap " << CYAN << name << RESET << " was Created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) 
{
	*this = other;
	std::cout << "|| ScavTrap Copy Constructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_isGuardingGate = other._isGuardingGate;
	
		std::cout << "|| ScavTrap " << _name << " assigned!" << std::endl;		
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		_energy--;
		std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << RED <<" attacks "
		<< RESET << "<" << GREEN << target << RESET << ">, causing "
		<< "<" << this->_attack << "> points of damage!" << std::endl;
	}
	else
	{
		std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << RED <<" takes "<< RESET << "<" << amount << "> \
points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		if (amount <= 100 && this->_hitPoints + amount <= 100)
			this->_hitPoints += amount;
		else
			this->_hitPoints = 100;
		_energy--;		
		std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << GREEN <<" Repairs "<< RESET << "<" 
		<< amount << "> points of life!" << std::endl;
	}
	else
	{
		std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_energy > 0 && _hitPoints > 0)
	{
		if (_isGuardingGate)
			std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">"
			<< " already in guarding gate!" << std::endl;
		else
		{
			_isGuardingGate = 1;		
			std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">"
			<< " Is in guarding gate!" << std::endl;
		}
	}
	else
	{
		std::cout << "|| ScavTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << std::endl;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " is being scrapped!" << std::endl;
}