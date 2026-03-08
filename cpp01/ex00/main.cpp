#include "Zombie.hpp"

int	main()
{
	Zombie* alfred = newZombie("Alfred");
	alfred->announce();
	randomChump("Giraldo");

	delete alfred;
}