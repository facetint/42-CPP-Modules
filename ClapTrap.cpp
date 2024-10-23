#include "ClapTrap.hpp"

ClasTrap::ClasTrap()
{
    std::cout << "Default Constructor called" << std::endl; 
}
ClasTrap::ClasTrap(std::string name)
{
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}
ClasTrap::ClasTrap(const ClasTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}
void ClasTrap::attack(const std::string& target)
{
   std::cout << "ClapTrap " << this->name <<  " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

