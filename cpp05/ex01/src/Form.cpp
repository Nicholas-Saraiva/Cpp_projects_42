#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _gradeExec(150), _gradeSign(150), _isSign(false)
{
}

Form::Form(const Form &other) : _name(other._name), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign), _isSign(other._isSign)
{}

Form::~Form()
{
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeExec(gradeExec), _gradeSign(gradeSign), _isSign(false)
{
	if (gradeSign < 1)
		throw(Form::GradeTooHighException());
	else if (gradeSign > 150)
		throw(Form::GradeTooLowException());
	if (gradeExec < 1)
		throw(Form::GradeTooHighException());
	else if (gradeExec > 150)
		throw(Form::GradeTooLowException());
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeSign() const
{
	return this->_gradeSign;
}

int Form::getGradeExec() const
{
	return this->_gradeExec;
}
int Form::getSign() const
{
	return this->_isSign;
}
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	_isSign = true;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSign = other._isSign;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &stream, Form const &other)
{
	stream << other.getName() << ", Form gradeExec " << other.getGradeExec() << ", Form gradeSign " << other.getGradeSign()
	<< ". Is Sign: " << other.getSign();
	return stream;
}