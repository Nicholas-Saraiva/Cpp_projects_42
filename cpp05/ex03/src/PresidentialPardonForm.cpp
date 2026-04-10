#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("President Pardon Request", 25, 5), _target("defaultTarget")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("President Pardon Request", 25, 5), _target(target)
{
}

void PresidentialPardonForm::toBeExecuted() const
{
	std::cout << _target << " has pardoned by Zaphod Beeblebrox" << std::endl;
}
