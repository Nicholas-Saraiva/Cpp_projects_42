#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string& target);
	void	toBeExecuted() const;
};