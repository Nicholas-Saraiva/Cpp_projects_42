#include <string>
#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Harl		harl;

	if (argc > 1) level = (std::string) argv[1];
	harl.complain(level);
}