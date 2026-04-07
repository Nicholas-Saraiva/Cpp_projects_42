#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_slots[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator=(const MateriaSource& other);
	~MateriaSource();

	void		learnMaeria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};