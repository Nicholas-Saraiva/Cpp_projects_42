#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- TEST 1: Basic Success ---" << std::endl;
	try
	{
		Bureaucrat  boss("The Boss", 1);
		Form        contract("Important Contract", 10, 5);

		std::cout << boss << std::endl;
		std::cout << contract << std::endl;

		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Grade Too Low to Sign ---" << std::endl;
	try
	{
		Bureaucrat  intern("The Intern", 150);
		Form        secretPlan("Area 51 Map", 1, 1);

		std::cout << intern << std::endl;
		std::cout << secretPlan << std::endl;

		intern.signForm(secretPlan);
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Form Creation Error (Too High) ---" << std::endl;
	try
	{
		Form illegalForm("Impossible Form", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Expected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Bureaucrat Increment Error ---" << std::endl;
	try
	{
		Bureaucrat god("God", 1);
		std::cout << god << std::endl;
		god.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "Expected Exception: " << e.what() << std::endl;
	}

	return 0;
}