#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
    std::cout << "Default constructor called - (AMateria)" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
    std::cout << "Parametric constructor called - (AMateria)" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
    std::cout << "Copy constructor called - (AMateria)" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called - (AMateria)" << std::endl;
}
AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Assignation operator called - (AMateria)" << std::endl;
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria::use() called" << std::endl;
}

