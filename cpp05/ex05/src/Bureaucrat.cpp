#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->_name	= other._name;
	this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade >= 1 && grade <= 150)
	{
		_grade = grade;
		_name = name;
	}
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException())
	
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_name	= other._name;
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message) 
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->_message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message) 
{}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->_message.c_str();
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other)
{
	stream << other.getName() + ">, bureaucrat grade " + std::to_string(other.getGrade());
	return stream;
}