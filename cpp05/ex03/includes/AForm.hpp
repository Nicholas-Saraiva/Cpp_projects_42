#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_gradeExec;
	const int			_gradeSign;
	bool				_isSign;
public:
	AForm();
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();

	AForm(std::string name, int gradeSign, int gradeExec);
 
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
	class NotSignedException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExec() const;
	int				getSign() const;
	void			beSigned(const Bureaucrat& b);
	void			execute(Bureaucrat const & executor) const;
	virtual void	toBeExecuted() const = 0;
};

std::ostream& operator<<(std::ostream& stream, AForm const& other);