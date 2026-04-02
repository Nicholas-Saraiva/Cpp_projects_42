#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "|| Create a default AMateria" << std::endl;
}

AMateria::AMateria(std::string type) : _type(type)
{
	std::cout << "|| Create a AMateria of type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "|| Create a AMateria by copy constructor: " << type << std::endl;

}

std::string const & AMateria::getType() const
{
	return this->_type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->_type = other._type;
	std::cout << "|| AMateria using copy operator" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "|| Is the end of a " << _type << " AMateria :<" << std::endl;
}
