#include "Zombie.hpp"
#include <algorithm>

int	main()
{
	Zombie* alfred = zombieHorde(5, "Alfred");
	std::for_each(&alfred[0], &alfred[5], std::mem_fun_ref( &Zombie::announce));
	delete[] alfred;
}