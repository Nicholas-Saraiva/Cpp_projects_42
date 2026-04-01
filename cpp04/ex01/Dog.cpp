#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "|| Create a nameless Dog" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog")
{
	this->_name = name;
	std::cout << "|| Created " << name << ", a Dog." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_name = other._name;
	std::cout << "|| Create a Dog by copy constructor: " << type << std::endl;

}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_name = other._name;
		std::cout << "|| Dog using copy operator" << std::endl;
	}
	return *this;
}

void	Dog::makeSound() const 
{
	std::cout << "The Dog Barks." << std::endl;
}

Dog::~Dog()
{
	std::cout << "|| Is the end of a " << type << std::endl;
}
