#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){};
Zombie::Zombie(std::string name) : name(name){}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " Died eating rot Brainzzz." << std::endl;
}