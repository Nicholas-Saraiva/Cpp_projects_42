#pragma once
#include <iomanip>
#include "Contact.hpp"

#define	MAX_CONTACT 8
#define CLEAR "\033[2J\033[H"

class Phonebook
{
	private:
		Contact	contacts[8];
		int		iterator;
	public:
		Phonebook();

		int		add();
		int		search();
		~Phonebook();
};
