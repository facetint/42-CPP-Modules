/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:42:57 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 20:04:40 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)  : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << _name << " has been created." << std::endl;
}
HumanA::~HumanA()
{
    std::cout << "HumanA " << _name << " has been destroyed." << std::endl;
}
void HumanA::attack()
{
    if  ((this) != NULL)
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
