/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:00:26 by facetint          #+#    #+#             */
/*   Updated: 2024/11/10 23:13:41 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor called - (FragTrap)" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "Parameterized constructor called - (FragTrap)" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called - (FragTrap)" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called - (FragTrap)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called - (FragTrap)" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::string name = getName();
	if (getEnergyPoint() > 0 && getHitPoint() > 0)
	{
		std::cout << GREEN_COLOR << "FragTrap " << name << " requests a high five!" << RESET << std::endl;
	}
	else if (getEnergyPoint() == 0)
	{
		std::cout << RED_COLOR << "FragTrap " << name << " has no energy left to request a high five" << std::endl;
	}
	else if (getHitPoint() <= 0)
	{
		std::cout << RED_COLOR << "FragTrap " << name << " is already dead!" << RESET << std::endl;
	}
}
