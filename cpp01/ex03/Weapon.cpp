#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name) : type(name){}

const std::string Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string weapon)
{
	this->type = weapon;
}

Weapon::~Weapon()
{
}
