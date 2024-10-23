#include "ClapTrap.hpp"

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
   std::cout << "ClapTrap " << this->name <<  " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

