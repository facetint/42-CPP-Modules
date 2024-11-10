#ifndef MATERIALSOURCE_HPP

# define MATERIALSOURCE_HPP

# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *_materias[4];
	int _materiasCount;

  public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif