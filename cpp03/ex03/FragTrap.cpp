#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "|| A default FragTrap was Created!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "|| FragTrap " << CYAN << name << RESET << " was Created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) 
{
	*this = other;
	std::cout << "|| FragTrap Copy Constructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);	
		std::cout << "FragTrap " << _name << " assigned!" << std::endl;		
	}
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		_energy--;
		std::cout << "|| FragTrap <" << CYAN << this->_name << RESET << ">" << RED <<" attacks "
		<< RESET << "<" << GREEN << target << RESET << ">, causing "
		<< "<" << this->_attack << "> points of damage!" << std::endl;
	}
	else
	{
		std::cout << "|| FragTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "|| FragTrap <" << CYAN << this->_name << RESET << ">" << RED <<" takes "<< RESET << "<" << amount << "> \
points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0 && _hitPoints > 0)
	{
		if (amount <= 100 && this->_hitPoints + amount <= 100)
			this->_hitPoints += amount;
		else
			this->_hitPoints = 100;
		_energy--;		
		std::cout << "|| FragTrap <" << CYAN << this->_name << RESET << ">" << GREEN <<" Repairs "<< RESET << "<" 
		<< amount << "> points of life!" << std::endl;
	}
	else
	{
		std::cout << "|| FragTrap <" << CYAN << this->_name << RESET << ">" << RED 
		<<" cannot take action" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "|| FragTrap " << _name << " is giving you a High Five! ╰( ^o^)╮" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is being scrapped!" << std::endl;
}