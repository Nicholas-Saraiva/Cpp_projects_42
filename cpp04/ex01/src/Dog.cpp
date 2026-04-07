#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "|| Create a nameless Dog" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog")
{
	this->_brain = new Brain();
	this->_name = name;
	std::cout << "|| Created " << name << ", a Dog." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	if (this != &other)
	{
		this->_brain = new Brain(*(other._brain));
		this->_name = other._name;
		std::cout << "|| Create a Dog by copy constructor: " << type << std::endl;
	}
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*(other._brain));
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

Brain *Dog::getBrain() const
{
	return this->_brain;
}


Dog::~Dog()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "|| Is the end of a " << type << std::endl;
}
