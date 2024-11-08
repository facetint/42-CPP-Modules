#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
        {
            delete this->_materias[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materias[i] != NULL)
            {
                delete this->_materias[i];
            }
            if (other._materias[i] != NULL)
            {
                this->_materias[i] = other._materias[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == NULL)
        {
            this->_materias[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
        {
            return this->_materias[i]->clone();
        }
    }
    return NULL;
}

