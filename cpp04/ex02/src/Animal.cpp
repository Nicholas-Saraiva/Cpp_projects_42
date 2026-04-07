#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "|| Create a default Animal" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "|| Create a Animal of type: " << type << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "|| Create a Animal by copy constructor: " << type << std::endl;

}

std::string Animal::getType() const
{
	return type;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	std::cout << "|| Animal using copy operator" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "|| Is the end of a " << type << " Animal :<" << std::endl;
}
