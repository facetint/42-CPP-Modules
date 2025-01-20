#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Serializer::~Serializer()
{
    std::cout << "Destructor called" << std::endl;
}

Serializer & Serializer::operator=(Serializer const & other)
{
    std::cout << "Assignation operator called" << std::endl;
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
