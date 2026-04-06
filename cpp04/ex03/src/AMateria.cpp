#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string type) : _type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return this->_type;
}


void AMateria::use(ICharacter &target)
{
	std::cout << "Default attack of a no type on " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
}
