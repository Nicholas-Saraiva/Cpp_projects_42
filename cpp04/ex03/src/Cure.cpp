#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria(other._type)
{
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *"  << std::endl;
}

Cure *Cure::clone() const
{
	return (new Cure());
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cure::~Cure()
{
}
