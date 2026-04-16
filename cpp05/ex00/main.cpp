#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat hermes("Hermes", 1);
		
		std::cout << hermes << std::endl;
		hermes.increment(); 
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error encountered: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	james("James", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error encountered: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	jailson("Jailson", 149);
		
		std::cout << jailson << std::endl;
		jailson.decrement();
		std::cout << jailson << std::endl;
		jailson.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error encountered: " << e.what() << std::endl;
	}
	
	
	return 0;
}