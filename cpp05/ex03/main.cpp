#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern  someRandomIntern;
	Bureaucrat boss("The CEO", 1);
	AForm* rrf;

	std::cout << "--- TEST 1: Success (Robotomy) ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 2: Success (Shrubbery) ---" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 3: Success (Pardon) ---" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Commoner");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 4: Failure (Invalid Name) ---" << std::endl;
	rrf = someRandomIntern.makeForm("coffee request", "Intern");
	if (!rrf)
		std::cout << "Intern correctly failed to create an unknown form." << std::endl;
	return 0;
}