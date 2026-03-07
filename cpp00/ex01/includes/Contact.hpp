#pragma once

#include <iostream>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact(){};
		Contact(std::string	list[5])
			: firstName(list[0]), lastName(list[1]),
			nickname(list[2]), phoneNumber(list[3]),
			darkestSecret(list[4]) {};
		~Contact(){};
};	

