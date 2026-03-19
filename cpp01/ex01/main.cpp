#include "Zombie.hpp"

int	main()
{
	int	nHorder = 5;

	Zombie* alfred = zombieHorde(nHorder, "Alfred");
	for (int i = 0; i < nHorder; i++)
		alfred[i].announce();
	delete[] alfred;
}