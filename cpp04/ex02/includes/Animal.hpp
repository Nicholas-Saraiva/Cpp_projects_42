#pragma once
#include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);

	std::string	getType() const;
	virtual void		makeSound() const = 0;
	Animal&	operator=(const Animal& other);
	virtual ~Animal();
};