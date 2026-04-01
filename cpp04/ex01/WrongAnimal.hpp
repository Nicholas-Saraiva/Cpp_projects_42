#pragma once
#include <string>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& other);

	std::string	getType() const;
	void		makeSound() const;
	WrongAnimal&	operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
};