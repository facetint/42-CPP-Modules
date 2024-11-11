/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:23 by facetint          #+#    #+#             */
/*   Updated: 2024/10/30 11:23:00 by facetint         ###   ########.fr       */
/*                                                                            */ 
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Default constructor called - (DiamondTrap)" << std::endl;
	this->_name = "DiamondTrap";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Parameterized constructor called - (DiamondTrap)" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Copy constructor called - (DiamondTrap)" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called - (DiamondTrap)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Copy assignment operator called - (DiamondTrap)" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

std::string DiamondTrap::getDiamondName() const
{
	return (this->_name);
}

void DiamondTrap::setDiamondName(std::string name)
{
	this->_name = name;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap identity: " << getDiamondName() << std::endl;
	std::cout << "Base ClapTrap identity: " << getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}