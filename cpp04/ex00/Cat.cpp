#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "|| Create a nameless Cat" << std::endl;
}

Cat::Cat(std::string name) : Animal("Cat")
{
	this->_name = name;
	std::cout << "|| Created " << name << ", a Cat." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_name = other._name;
	std::cout << "|| Create a Cat by copy constructor: " << type << std::endl;

}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_name = other._name;
		std::cout << "|| Cat using copy operator" << std::endl;
	}
	return *this;
}

void	Cat::makeSound() const 
{
	std::cout << "The cat Miau." << std::endl;
}

Cat::~Cat()
{
	std::cout << "|| Is the end of a " << type << std::endl;
}
