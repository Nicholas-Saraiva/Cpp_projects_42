#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "|| Create a nameless Cat" << std::endl;
}

Cat::Cat(std::string name) : Animal("Cat")
{
	this->_name = name;
	this->_brain = new Brain();
	std::cout << "|| Created " << name << ", a Cat." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	if (this != &other)
	{
		this->_brain = new Brain(*(other._brain));
		this->_name = other._name;
		std::cout << "|| Create a Cat by copy constructor: " << type << std::endl;
	}
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*(other._brain));
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

Brain *Cat::getBrain() const
{
	return this->_brain;
}

Cat::~Cat()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "|| Is the end of a " << type << std::endl;
}
