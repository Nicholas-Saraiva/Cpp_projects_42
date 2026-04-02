#include <string>
#include "ICharacter.hpp"

class Ice
{
public:
	Ice();
	Ice(const Ice &other);

	virtual Ice*clone() const = 0;
	virtual void	use(ICharacter &target);
	
	std::string const & getType() const;
	&Ice	operator=(const Ice &other);
	virtual ~Ice();
};