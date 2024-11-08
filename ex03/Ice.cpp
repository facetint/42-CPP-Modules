#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default constructor called - (Ice)" << std::endl;
}

Ice::Ice(const Ice& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Ice)" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Destructor called - (Ice)" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Assignation operator called - (Ice)" << std::endl;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
