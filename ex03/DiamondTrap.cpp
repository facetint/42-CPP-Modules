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

DiamondTrap::DiamondTrap() : ClapTrap(""), ScavTrap(""), FragTrap("")
{
	std::cout << "Default constructor called - (DiamondTrap)" << std::endl;
	setDiamondName("");
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Parameterized constructor called - (DiamondTrap)" << std::endl;
	setDiamondName(name);
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other)
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
		this->_name = other.getDiamondName();
		this->ClapTrap::operator=(other);
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