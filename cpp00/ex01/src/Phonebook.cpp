#include <iomanip>
#include "Phonebook.hpp"


Phonebook::Phonebook(){}

void Phonebook::add()
{
	int	number_of_msg = 6;
	std::string	msg[6] = {
		"Adding Contact",
		"Insert First Name: ",
		"Insert Last Name: ",
		"Insert Nickname: ",
		"Insert Phone Number: ",
		"Insert Darkest Secret: ",		
	};
	std::string	list[5];

	std::cout << std::setfill('-')<< std::setw(msg[0].size() + 10) 
			<< msg[0] << std::setw(10) << "" 
			<< std::setfill('-') << std::endl;
	for (int i = 1; i < number_of_msg; i++)
	{
		std::cout << msg[i];
		if (!std::getline(std::cin, list[i - 1]) || list[i - 1].empty())
		{
			std::cout << "Empty input is not valid" << std::endl;
			return ;
		}
	}
	this->iterator = this->iterator % MAX_CONTACT;
	this->contacts[this->iterator] = Contact(list);
	this->iterator++;
}

Phonebook::~Phonebook(){}
