#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string	_name;
	Brain		*_brain;
public:
	Dog();
	Dog(std::string name);
	Dog(const Dog& other);

	void	makeSound() const;
	Brain*	getBrain() const;
	Dog&	operator=(const Dog& other);
	~Dog();
};
