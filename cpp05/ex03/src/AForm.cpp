#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("Default"), _gradeExec(150), _gradeSign(150), _isSign(false)
{
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign), _isSign(other._isSign)
{}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeExec(gradeExec), _gradeSign(gradeSign), _isSign(false)
{
	if (gradeSign < 1)
		throw(AForm::GradeTooHighException());
	else if (gradeSign > 150)
		throw(AForm::GradeTooLowException());
	if (gradeExec < 1)
		throw(AForm::GradeTooHighException());
	else if (gradeExec > 150)
		throw(AForm::GradeTooLowException());
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int AForm::getGradeExec() const
{
	return this->_gradeExec;
}
int AForm::getSign() const
{
	return this->_isSign;
}
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	_isSign = true;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSign = other._isSign;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Signal is not assigned!";
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	this->toBeExecuted();
}

std::ostream &operator<<(std::ostream &stream, AForm const &other)
{
	stream << other.getName() << ", AForm gradeExec " << other.getGradeExec() << ", AForm gradeSign " << other.getGradeSign()
	<< ". Is Sign: " << other.getSign();
	return stream;
}