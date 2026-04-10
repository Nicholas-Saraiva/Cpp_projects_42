#pragma once
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string& target);
	void	toBeExecuted() const;
};