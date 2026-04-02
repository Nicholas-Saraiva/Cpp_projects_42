#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter()
{
	for (int i = 0; i < MAXSLOTS; i++)
		this->slots[i] = NULL;
	std::cout << "|| Create a default ICharacter" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other)
{

	for (int i = 0; i < MAXSLOTS; i++)
		this->slots[i] = other.slots[i];
	std::cout << "|| Create a ICharacter by copy constructor: " << _type << std::endl;

}

std::string const & ICharacter::getType() const
{
	return this->_type;
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
	this->_type = other._type;
	std::cout << "|| ICharacter using copy operator" << std::endl;
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << "|| Is the end of a " << _type << " ICharacter :<" << std::endl;
}
