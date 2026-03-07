#include "Phonebook.hpp"

void	clear()
{
	std::cout << "\033[2J\033[H";
	std::cout << "80s Contact Always with you 🫩" << std::endl;
}
int	main()
{
	Phonebook pb;
	std::string	msg[] = {
			"80s Contact Always with you 🫩",
			"Text Your option (ADD, SEARCH, EXIT) 😒: ",
			"What are you trying to do??? 😠",
			"HaHa Nice Try 😤"
	};
	std::string	line;
	std::cout << msg[0] << std::endl;
	while(true)
	{
		std::cout << std::endl;
		std::cout << msg[1];
		if (!std::getline(std::cin, line))
			return(0);
		if (line.empty())
			std::cout << msg[3] << std::endl;
		else if (line == ("ADD"))
		{
			if (!pb.add())
				clear();
		}
		else if (line == ("SEARCH"))
		{
			clear();
			pb.search();
		}
		else if (line == ("EXIT"))
			return (0);
		else
			std::cout << msg[2] << std::endl;
	}
	return (0);
}