#pragma once
#include <string>

class Bureaucrat
{
private:
	const std::string	_name;
	int			_grade;
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
	void		increment();
	void		decrement();
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat const& other);