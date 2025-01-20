#include "Data.hpp"

Data::Data()
{
    std::cout << "Default constructor called" << std::endl;
}

Data::Data(uintptr_t value)
{
    std::cout << "Parametric constructor called" << std::endl;
    _value = value;
}

Data::Data(Data const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Data::~Data()
{
    std::cout << "Destructor called" << std::endl;
}

Data & Data::operator=(Data const & other)
{
    std::cout << "Assignation operator called" << std::endl;
    _value = other._value;
    return *this;
}

uintptr_t Data::getValue() const
{
    return _value;
}

void Data::setValue(uintptr_t value)
{
    _value = value;
}

