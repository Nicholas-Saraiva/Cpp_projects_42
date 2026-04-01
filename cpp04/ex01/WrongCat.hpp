#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string	_name;
public:
	WrongCat();
	WrongCat(std::string name);
	WrongCat(const WrongCat& other);

	void	makeSound() const;
	WrongCat&	operator=(const WrongCat& other);
	~WrongCat();
};
