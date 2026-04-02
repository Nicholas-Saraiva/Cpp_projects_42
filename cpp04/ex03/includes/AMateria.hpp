#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(const AMateria& other);
	AMateria(std::string const& type);

	std::string const & getType() const;
	&AMateria	operator=(const AMateria& other);
	virtual AMateria*clone() const = 0;
	virtual void	use(ICharacter& target);
	virtual ~AMateria();
};