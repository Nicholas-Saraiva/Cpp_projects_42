#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "|| Create a default AMateria" << std::endl;
}

AMateria::AMateria(std::string type) : type(type)
{
	std::cout << "|| Create a AMateria of type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "|| Create a AMateria by copy constructor: " << type << std::endl;

}

std::string AMateria::getType() const
{
	return type;
}

void AMateria::makeSound() const
{
	std::cout << "|| The AMateria Speaks!!!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->type = other.type;
	std::cout << "|| AMateria using copy operator" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "|| Is the end of a " << type << " AMateria :<" << std::endl;
}
