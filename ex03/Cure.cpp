#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default constructor called - (Cure)" << std::endl;
}

Cure::Cure(const Cure& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Cure)" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Destructor called - (Cure)" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Assignation operator called - (Cure)" << std::endl;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

