/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:59 by facetint          #+#    #+#             */
/*   Updated: 2024/10/24 18:01:51 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2("Claptrap2");

    claptrap.attack("Claptrap2");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(5);
    claptrap.fight(claptrap2);
    claptrap.displayStats();
    claptrap2.displayStats();
    return 0;

}