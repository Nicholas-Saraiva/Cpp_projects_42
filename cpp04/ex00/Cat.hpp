#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
private:
	std::string	_name;
public:
	Cat();
	Cat(std::string name);
	Cat(const Cat& other);

	void	makeSound() const;
	Cat&	operator=(const Cat& other);
	~Cat();
};
