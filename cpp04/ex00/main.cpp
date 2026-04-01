#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "-=-=-= Subject Test =-=-=-" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "-=-=-= Wrong Animal =-=-=-" << std::endl;
	const WrongAnimal*	cat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << "-=-=-= Delete All =-=-=-" << std::endl;
	delete	j;
	delete i;
	delete meta;
	delete cat;
	return 0;
}