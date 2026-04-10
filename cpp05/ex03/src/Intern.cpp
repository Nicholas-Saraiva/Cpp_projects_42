#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string	formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*MyPointer[])(std::string) =
			{&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};

	for (int i = 0; i < 3; i++)
	{
		if (name == formTypes[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*MyPointer[i])(target);
		}
	}
	std::cerr << "Error: Form name " << name << " does not exist." << std::endl;
	return NULL;
}
