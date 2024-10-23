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