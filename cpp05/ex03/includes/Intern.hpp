#pragma once
#include <string>
#include "AForm.hpp"

class Intern
{
private:
	AForm*	makeShrubbery(std::string target);
	AForm*	makeRobotomy(std::string target);
	AForm*	makePardon(std::string target);

public:
	Intern();
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern();

	AForm	*makeForm(std::string name, std::string target);
};