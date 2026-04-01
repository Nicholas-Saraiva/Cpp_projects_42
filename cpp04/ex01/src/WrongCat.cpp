#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "|| Create a nameless WrongCat" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal("WrongCat")
{
	this->_name = name;
	std::cout << "|| Created " << name << ", a WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->_name = other._name;
	std::cout << "|| Create a WrongCat by copy constructor: " << type << std::endl;

}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->_name = other._name;
		std::cout << "|| WrongCat using copy operator" << std::endl;
	}
	return *this;
}

void	WrongCat::makeSound() const 
{
	std::cout << "The WrongCat Miau." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "|| Is the end of a " << type << std::endl;
}
