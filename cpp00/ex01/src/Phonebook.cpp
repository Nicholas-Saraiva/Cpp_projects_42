#include "Phonebook.hpp"

Phonebook::Phonebook() : iterator(0){}

int	Phonebook::add()
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

	std::cout << CLEAR;
	std::cout << std::setfill('-')<< std::setw(msg[0].size() + 10) 
			<< msg[0] << std::setw(10) << "" 
			<< std::setfill('-') << std::endl;
	for (int i = 1; i < number_of_msg; i++)
	{
		std::cout << msg[i];
		if (!std::getline(std::cin, list[i - 1]) || list[i - 1].empty())
		{
			std::cout << "Empty input is not valid" << std::endl;
			return (1);
		}
	}
	this->iterator = this->iterator % MAX_CONTACT;
	this->contacts[this->iterator] = Contact(list);
	this->iterator++;
	return (0);
}

int	Phonebook::search()
{
	std::string	msg[] = {
		"index|",
		"first name|",
		"last name|",
		"nickname|",
	};
	for (int i = 0; i < 4; i++)
		std::cout << std::right << std::setfill(' ')
			<< std::setw(11) << msg[i];
	std::cout << std::endl;
	if (this->iterator == 0)
		std::cout << std::right << std::setfill(' ')
				<< std::setw(37) << "😭 ¿No Contacts? 😭" << std::endl;
	for (int i = 0; i < this->iterator; i++)
	{
		std::cout << std::right << std::setfill(' ')
			<< std::setw(10) << i << "|";
		if (this->contacts[i].getName().size() > 10)
			std::cout << this->contacts[i].getName().substr(0, 9) + ".|";
		else
			std::cout << std::right << std::setfill(' ')
				<< std::setw(10) << this->contacts[i].getName() << "|";
		if (this->contacts[i].getLastName().size() > 10)
			std::cout << this->contacts[i].getLastName().substr(0, 9) + ".|";
		else
			std::cout << std::right << std::setfill(' ')
				<< std::setw(10) << this->contacts[i].getLastName() << "|";
		if (this->contacts[i].getNickname().size() > 10)
			std::cout << this->contacts[i].getNickname().substr(0, 9) + ".|";
		else
			std::cout << std::right << std::setfill(' ')
				<< std::setw(10) << this->contacts[i].getNickname() << "|";
		std::cout << std::endl;
	}
	return (0);
}

Phonebook::~Phonebook(){}
