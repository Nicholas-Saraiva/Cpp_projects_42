#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "|| Create a default WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "|| Create a WrongAnimal of type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "|| Create a WrongAnimal by copy constructor: " << type << std::endl;

}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "|| The WrongAnimal Speaks!!!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "|| WrongAnimal using copy operator" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "|| Is the end of a " << type << " WrongAnimal :<" << std::endl;
}
