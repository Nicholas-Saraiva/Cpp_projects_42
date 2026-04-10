#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Request", 145, 137), _target("defaultTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Request", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::toBeExecuted() const
{
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "    c    " << std::endl;
		file << "   ccc   " << std::endl;
		file << "  ccccc  " << std::endl;
		file.close();
	}
}
