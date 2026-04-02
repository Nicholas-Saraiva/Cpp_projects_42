#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "|| Create a default Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "|| Create a Ice by copy constructor: " << type << std::endl;

}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target->type << " *"  << std::endl;
}

AMateria *Ice::clone()
{
	return nullptr;
}

std::string Ice::getType() const
{
	return type;
}

void Ice::makeSound() const
{
	std::cout << "|| The Ice Speaks!!!" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	this->type = other.type;
	std::cout << "|| Ice using copy operator" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "|| Is the end of a " << type << " Ice :<" << std::endl;
}
