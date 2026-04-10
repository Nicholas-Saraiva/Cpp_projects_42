#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_gradeExec;
	const int			_gradeSign;
	bool				_isSign;
public:
	Form();
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	Form(std::string name, int gradeSign, int gradeExec);
 
	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	std::string	getName() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	int			getSign() const;
	void		beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& stream, Form const& other);