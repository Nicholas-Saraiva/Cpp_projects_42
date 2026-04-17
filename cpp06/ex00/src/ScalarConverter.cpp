#include "ScalarConverter.hpp"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

void ScalarConverter::convert(std::string item)
{
	char*	end;
	int		i = std::strtol(item.c_str(), NULL, 10);
	double	d = std::strtod(item.c_str(), &end);
	
	std::cout << "This is my end" << *end << std::endl;

	if (*end == '\0' || (*end == 'f' && *(++end) == '\0' ))
	{
		std::cout << "char: ";
		if ( i > 32 && i <= 126 )
			std::cout << "'" << std::fixed << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		std::cout << std::fixed << static_cast<int>(d) << std::endl;
		std::cout << "float: ";
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: ";
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
	{
		const std::string arr[] = {"char: ", "int: ", "float: ", "double: ", ""};
		for (int i = 0; !arr[i].empty(); i++)
		{
			std::cout << arr[i];
			if (arr[i] == "char: " || arr[i] == "int: ")
				std::cout << "impossible" << std::endl;
			else if (arr[i] == "float: ")
				std::cout << "nanf" << std::endl;
			else
				std::cout << "nan" << std::endl;
		}
	}
}