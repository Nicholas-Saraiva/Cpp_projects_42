#pragma once

#include <string>
#include "ICharacter.hpp"

class Ice
{	
public:
	Ice();
	Ice(const Ice &other);

	virtual void	use(ICharacter &target);
	
	AMateria*	clone();
	std::string const & getType() const;
	Ice&	operator=(const Ice &other);
	virtual ~Ice();
};