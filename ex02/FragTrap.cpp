#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
    std::cout << "Default constructor called - (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "Parameterized constructor called - (FragTrap)" << std::endl;
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copy constructor called - (FragTrap)" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called - (FragTrap)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy assignment operator called - (FragTrap)" << std::endl;
    if (this != &other)
        FragTrap::ClapTrap::operator=(other);
    return *this;
}




