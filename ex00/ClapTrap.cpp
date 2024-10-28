/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:54 by facetint          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:31 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "Parameterized constructor called" << std::endl;
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

void ClapTrap::attack(const std::string &target)
{
	if (getEnergyPoint() == 0)
	{
		std::cout << RED_COLOR << "ClapTrap " << getName() << " has no energy left to attack!" << RESET << std::endl;
		return ;
	}
	if (getHitPoint() == 0)
	{
		std::cout << RED_COLOR << "ClapTrap " << getName() << " is already dead!" << RESET << std::endl;
		return ;
	}
	std::cout << BLUE_COLOR << "ClapTrap " << getName() << " attacks " << target << " ,causing " << getAttackDamage() << " points of damage!" << RESET << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << RED_COLOR << "ClapTrap " << getName() << " is already dead!" << RESET << std::endl;
        return;
    }
    else if (amount == 0)
    {
        std::cout << WHITE_COLOR << "ClapTrap " << getName() << " takes 0 points of damage!" << RESET << std::endl;
        return;
    }
    else
    {
        if (getHitPoint() - amount <= 0)
        {
            setHitPoint(0);
            std::cout << RED_COLOR << "ClapTrap " << getName() << " is dead!" << RESET << std::endl;
            return;
        }
        std::cout << BLUE_COLOR << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << RESET << std::endl;
        setHitPoint(getHitPoint() - amount);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHitPoint() == 0)
    {
        std::cout << RED_COLOR << "ClapTrap " << getName() << " is already dead!" << RESET << std::endl;
        return;
    }
    if ((unsigned long)(hitPoint + amount) > UINT_MAX)
        amount = UINT_MAX - hitPoint;
    setHitPoint(getHitPoint() + amount);
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << BLUE_COLOR << "ClapTrap " << getName() << " is repaired for " << amount << " points!" << RESET << std::endl;
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
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

void ClapTrap::displayStats() const
{
    std::cout << WHITE_COLOR << "===== " << RESET << PURPLE_COLOR << "ClapTrap Stats" << RESET << WHITE_COLOR << " =====" << std::endl;
    std::cout << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Hit Points: " << getHitPoint() << std::endl;
    std::cout << "Energy Points: " << getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << getAttackDamage() << std::endl;

    if (getHitPoint() == 0)
        std::cout << RED_COLOR << getName() << " is dead!" << RESET << std::endl;
    else
        std::cout << GREEN_COLOR << getName() << " is alive!" << RESET << std::endl;

    std::cout << WHITE_COLOR << "=========================="  << std::endl;
    std::cout << RESET << std::endl;
}
