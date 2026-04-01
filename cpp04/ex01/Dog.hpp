#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
private:
	std::string	_name;
public:
	Dog();
	Dog(std::string name);
	Dog(const Dog& other);

	void	makeSound() const;
	Dog&	operator=(const Dog& other);
	~Dog();
};
