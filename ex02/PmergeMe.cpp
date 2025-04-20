#include "PmergeMe.hpp"

Vector::Vector() {}

Vector::Vector(int ac, char **av) : FordJohnson()
{
    parseInputArguments(ac, av);
}

Vector::~Vector() {}

Vector::Vector(const Vector &other) : FordJohnson(other) {}

Vector &Vector::operator=(const Vector &other)
{
    if (this != &other)
    {
        FordJohnson::operator=(other);
    }
    return *this;
}

Deque::Deque() {}

Deque::Deque(int ac, char **av) : FordJohnson()
{
    parseInputArguments(ac, av);
}

Deque::~Deque() {}

Deque::Deque(const Deque &other) : FordJohnson(other) {}

Deque &Deque::operator=(const Deque &other)
{
    if (this != &other)
    {
        FordJohnson::operator=(other);
    }
    return *this;
}