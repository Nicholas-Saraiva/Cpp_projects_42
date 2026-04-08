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
	return 0;
}