/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:54 by facetint          #+#    #+#             */
/*   Updated: 2024/10/30 11:07:15 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return (this->_energyPoint);
}

unsigned int ClapTrap::getHitPoint() const
{
	return (this->_hitPoint);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}

void ClapTrap::setEnergyPoint(unsigned int energyPoint)
{
	this->_energyPoint = energyPoint;
}
void ClapTrap::setHitPoint(unsigned int hitPoint)
{
	this->_hitPoint = hitPoint;
}
void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
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
		return ;
	}
	else if (amount == 0)
	{
		std::cout << WHITE_COLOR << "ClapTrap " << getName() << " takes 0 points of damage!" << RESET << std::endl;
		return ;
	}
	else
	{
		if (getHitPoint() <= amount)
		{
			setHitPoint(0);
			std::cout << RED_COLOR << "ClapTrap " << getName() << " is dead!" << RESET << std::endl;
			return ;
		}
		std::cout << BLUE_COLOR << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << RESET << std::endl;
		setHitPoint(getHitPoint() - amount);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoint() == 0)
	{
		std::cout << RED_COLOR << "ClapTrap " << getName() << " is already dead and cannot be repaired!" << RESET << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << RED_COLOR << "ClapTrap " << getName() << " has no energy left to repair!" << RESET << std::endl;
		return ;
	}
	if (amount > UINT_MAX - getHitPoint())
		amount = UINT_MAX - getHitPoint();
	setHitPoint(getHitPoint() + amount);
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << BLUE_COLOR << "ClapTrap " << getName() << " is repaired for " << amount << " points!" << RESET << std::endl;
}

void ClapTrap::displayStats() const
{
	std::cout << WHITE_COLOR << "===== " << RESET << PURPLE_COLOR << " STATS " << RESET << WHITE_COLOR << " =====" << std::endl;
	std::cout << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Hit Points: " << getHitPoint() << std::endl;
	std::cout << "Energy Points: " << getEnergyPoint() << std::endl;
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;

	if (getHitPoint() == 0)
		std::cout << RED_COLOR << getName() << " is dead!" << RESET << std::endl;
	else
		std::cout << GREEN_COLOR << getName() << " is alive!" << RESET << std::endl;

	std::cout << WHITE_COLOR << "==========================" << std::endl;
	std::cout << RESET << std::endl;
}
