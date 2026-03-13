#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I'am a DEBUGER." << std::endl;
}

void Harl::info(void)
{
	std::cout << "I'am a INFO." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I'am a WARNING." << std::endl;
}

void Harl::error(void)
{
	std::cout << "I'am a ERROR" << std::endl;
}

Harl::Harl()
{
}

void Harl::complain(std::string level)
{
	void (Harl::*MyPointer[])(void) =
		 {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
			(this->*MyPointer[i])();
	}
}

Harl::~Harl()
{
}
