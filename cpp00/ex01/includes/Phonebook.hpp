#pragma once
#include "Contact.hpp"

#define	MAX_CONTACT 8

class Phonebook
{
	private:
		Contact	contacts[8];
		size_t	iterator;
	public:
		Phonebook();

		void	add();
		void	search();
		~Phonebook();
};
