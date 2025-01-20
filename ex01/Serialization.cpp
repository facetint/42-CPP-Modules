#include "Serialization.hpp"

Serialization::Serialization()
{
    std::cout << "Default constructor called" << std::endl;
}

Serialization::Serialization(Serialization const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Serialization::~Serialization()
{
    std::cout << "Destructor called" << std::endl;
}

Serialization & Serialization::operator=(Serialization const & other)
{
    std::cout << "Assignation operator called" << std::endl;
    (void)other;
    return *this;
}

uintptr_t Serialization::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialization::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
