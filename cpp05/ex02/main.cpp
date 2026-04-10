#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{

	std::cout << "--- TEST 1: Shrubbery (Sign 145, Exec 137) ---" << std::endl;
	try
	{
		Bureaucrat lowRank("Junior Clerk", 140);
		ShrubberyCreationForm shrub("backyard");

		std::cout << lowRank << std::endl;
		lowRank.signForm(shrub);
		
		lowRank.executeForm(shrub); 
		Bureaucrat midRank("Senior Clerk", 130);
		midRank.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Robotomy (Sign 72, Exec 45) ---" << std::endl;
	try {
		Bureaucrat officer("Officer", 40);
		RobotomyRequestForm robot("Bender");

		officer.signForm(robot);
		officer.executeForm(robot);
		officer.executeForm(robot);
		officer.executeForm(robot);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Presidential Pardon (Sign 25, Exec 5) ---" << std::endl;
	try 
	{
		Bureaucrat president("Zaphod", 1);
		PresidentialPardonForm pardon("Ford Prefect");

		president.signForm(pardon);
		president.executeForm(pardon);
	} 
	catch (std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Unsigned Form Execution ---" << std::endl;
	Bureaucrat boss("The Boss", 1);
	RobotomyRequestForm robot("Target");

	boss.executeForm(robot); 
	return 0;
}