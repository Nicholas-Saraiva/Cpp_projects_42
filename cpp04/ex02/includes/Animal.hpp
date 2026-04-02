#pragma once
#include <string>

class Animal
{
protected:
	std::string	type;
	std::string	sound;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);

	virtual std::string	getType() const;
	virtual void		makeSound() const = 0;
	virtual ~Animal();
};