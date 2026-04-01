#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	std::string	_name;
	Brain		*_brain;
public:
	Cat();
	Cat(std::string name);
	Cat(const Cat& other);

	void	makeSound() const;
	Cat&	operator=(const Cat& other);
	~Cat();
};
