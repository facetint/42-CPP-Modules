/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:43 by facetint          #+#    #+#             */
/*   Updated: 2024/11/10 23:23:27 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called - (ScavTrap)" << std::endl;
	this->_name = "ScavTrap";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "Parameterized constructor called - (ScavTrap)" << std::endl;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called - (ScavTrap)" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called - (ScavTrap)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called - (ScavTrap)" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoint() == 0)
	{
		std::cout << RED_COLOR << "ScavTrap " << getName() << " has no energy left to attack!" << RESET << std::endl;
		return ;
	}
	if (getHitPoint() == 0)
	{
		std::cout << RED_COLOR << "ScavTrap " << getName() << " is already dead!" << RESET << std::endl;
		return ;
	}
	std::cout << BLUE_COLOR << "ScavTrap " << getName() << " attacks " << target << ",causing " << getAttackDamage() << " points of damage !" << RESET << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void ScavTrap::guardGate()
{
	std::string name = getName();
	if (getEnergyPoint() > 0 && getHitPoint() > 0)
	{
		std::cout << GREEN_COLOR << "ScavTrap " << name << " has entered Gate Keeper mode!" << RESET << std::endl;
	}
	else if (getEnergyPoint() == 0)
	{
		std::cout << RED_COLOR << "ScavTrap " << name << " cannot enter Gate Keeper mode due to insufficient energy!" << RESET << std::endl;
	}
	else if (getHitPoint() <= 0)
	{
		std::cout << RED_COLOR << "ScavTrap " << name << " is already dead!" << RESET << std::endl;
	}
}
