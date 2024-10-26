/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:54 by facetint          #+#    #+#             */
/*   Updated: 2024/10/26 17:41:58 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
    this->name = name;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
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

std::string ClapTrap::getName() const
{
    return this->name;
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
  if (getEnergyPoint() == 0 || getHitPoint() == 0 || getAttackDamage() == 0)
{
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << getName() <<  " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    setEnergyPoint(getEnergyPoint() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }
    else if (amount == 0)
    {
        std::cout << "ClapTrap " << getName() << " takes 0 points of damage!" << std::endl;
        return;
    }
    else
    {
        if (getHitPoint() - amount <= 0)
        {
            setHitPoint(0);
            std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
            return;
        }
        std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
        setHitPoint(getHitPoint() - amount);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }
    if ((unsigned long)(hitPoint + amount) > UINT_MAX)
        amount = UINT_MAX - hitPoint;
    setHitPoint(getHitPoint() + amount);
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "ClapTrap " << getName() << " is repaired for " << amount << " points!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void ClapTrap::displayStats() const
{
    std::cout << "===== ClapTrap Stats =====" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Hit Points: " << getHitPoint() << std::endl;
    std::cout << "Energy Points: " << getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << getAttackDamage() << std::endl;

    if (getHitPoint() == 0)
        std::cout << getName() << " is dead!" << std::endl;
    else
        std::cout << getName() << " is alive!" << std::endl;

    std::cout << "==========================" << std::endl;
}

