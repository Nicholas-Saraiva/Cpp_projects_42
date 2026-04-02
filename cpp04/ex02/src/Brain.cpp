#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "|| Create a default Brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "|| Create a Brain by copy constructor." << std::endl;

}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < maxIdeas; i++)
			this->ideas[i] = other.ideas[i];
		std::cout << "|| Brain using copy operator" << std::endl;
	}
	return *this;
}

void Brain::putIdea(std::string	idea)
{
	if (this->_it == maxIdeas - 1)
	{
		std::cout << "Cannot store more ideas" << std::endl;
		return ;
	}
	this->ideas[_it] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout << "dont have that ideia" << std::endl;
		return std::string();
	}
	return this->ideas[i];
}

Brain::~Brain()
{
	std::cout << "|| The Brain cannot think no more." << std::endl;
}
