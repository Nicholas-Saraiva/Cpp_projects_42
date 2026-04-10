#pragma once
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(std::string name, int grade);
 
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
	int			getGrade() const;
	void		executeForm(AForm const & form) const;
	void		increment();
	void		decrement();
	void		signForm(AForm& form);
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat const& other);