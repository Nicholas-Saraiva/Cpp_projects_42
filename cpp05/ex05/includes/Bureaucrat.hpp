#include <string>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(std::string name, int grade);

	class GradeTooHighException : public std::exception
	{
		private:
			std::string	_message;
		public:
			GradeTooHighException(const	std::string& message);
			const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
			std::string	_message;
		public:
			GradeTooLowException(const	std::string& message);
			const char*	what() const throw();
	};

	std::string	getName() const;
	int			getGrade() const;
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat const& other);