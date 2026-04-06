#pragma once

#include <string>
#include "ICharacter.hpp"

class Ice : public AMateria
{	
public:
	Ice();
	Ice(const Ice &other);
	Ice&	operator=(const Ice &other);
	virtual ~Ice();
	
	Ice*	clone() const;
	void	use(ICharacter &target);
};