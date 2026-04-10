#pragma once
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string& target);
	void	toBeExecuted() const;
};