#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other._type)
{
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"  << std::endl;
}

Ice *Ice::clone() const
{
	return (new Ice());
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice::~Ice()
{
}
