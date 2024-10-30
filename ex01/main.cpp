/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:00:10 by facetint          #+#    #+#             */
/*   Updated: 2024/10/30 11:00:11 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav("Clappy");
	scav.displayStats();
	scav.attack("Enemy");
	for (int i = 0; i < 5; ++i)
	{
		scav.attack("Enemy");
	}
	scav.displayStats();
	scav.guardGate();
	scav.setEnergyPoint(0);
	scav.guardGate();
	scav.setHitPoint(0);
	scav.attack("Another Enemy");
	scav.guardGate();
	scav.displayStats();
	return (0);
}
