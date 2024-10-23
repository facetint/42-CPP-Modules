#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl; 
}
ClapTrap::ClapTrap(std::string name)
{
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}
unsigned int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;
}

unsigned int ClapTrap::getEnergyPoint() const
{
    return this->energyPoint;
}

unsigned int ClapTrap::getHitPoint() const
{
    return this->hitPoint;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
}

void ClapTrap::setEnergyPoint(unsigned int energyPoint)
{
    this->energyPoint = energyPoint;
}
void ClapTrap::setHitPoint(unsigned int hitPoint)
{
    this->hitPoint = hitPoint;
}
void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::attack(const std::string& target)
{
   std::cout << "ClapTrap " << getName() <<  " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }

    if (getHitPoint() < amount)
    {
        std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
        amount = hitPoint;
        return;
    }

    setHitPoint(getHitPoint() - amount);
    std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }
    if (getHitPoint() + amount > 10)
    {
        std::cout << "ClapTrap " << getName() << " is fully repaired!" << std::endl;
        setHitPoint(10);
        return;
    }
    setHitPoint(getHitPoint() + amount);
    std::cout << "ClapTrap " << getName() << " is repaired for " << amount << " points!" << std::endl;
}
