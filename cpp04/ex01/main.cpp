#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "-=-=-= Subject Test =-=-=-" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << "-=-=-= Other Test =-=-=-" << std::endl;
	const int numAnimals = 4;
    Animal* animals[numAnimals];

    std::cout << "--- 1. CREATING ANIMALS ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
	{
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- 2. TESTING DEEP COPY ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    basic.getBrain()->putIdea("I have a ideia");
    std::cout << basic.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- 3. DELETING ARRAY (The Leak Test) ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];

    return 0;
}