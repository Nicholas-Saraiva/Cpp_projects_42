#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("defaultTarget")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), _target(target)
{
}

void RobotomyRequestForm::toBeExecuted() const
{
	static bool	isSeed = false;
	if (!isSeed)
	{
		srand(time(0));
		isSeed = true;
	}
	std::cout << "... dril dril dril noises ..." << std::endl;
	if (rand() % 2)
	{
		std::cout << "... fortunately your robotomized works :) ..." << std::endl;
	}
	else
		std::cout << "... infortunately your robotomized doesn't work :( ..." << std::endl;
}
