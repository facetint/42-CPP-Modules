/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:37 by facetint          #+#    #+#             */
/*   Updated: 2024/10/30 11:01:38 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("Diamondy");
	diamond.displayStats();
	diamond.takeDamage(40);
	diamond.beRepaired(20);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.displayStats();
	return (0);
}
