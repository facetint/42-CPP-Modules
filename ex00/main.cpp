/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:03:43 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:03:44 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z;
	Zombie	*ptr;

	z.setName("Zombie1");
	z.announce();
	ptr = newZombie("Foo");
	ptr->announce();
	randomChump("Blades");
	delete	ptr;
	return (0);
}
