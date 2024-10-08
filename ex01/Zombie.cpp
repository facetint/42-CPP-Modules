/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:34:19 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:20 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << this->_name << "Zombie created" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->_name << " is destroyed" << std::endl;
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}
void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
