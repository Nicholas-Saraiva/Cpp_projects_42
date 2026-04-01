#pragma once
#include <string>

const int	maxIdeas = 100;

class Brain
{
private:
	std::string	ideas[maxIdeas];
	int			_it;
public:
	Brain();
	Brain(const Brain& other);

	Brain&	operator=(const Brain& other);
	void		putIdea(std::string	idea);
	std::string	getIdea(int i) const;
	~Brain();
};
