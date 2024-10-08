/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:34:16 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:17 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    int num = 5;
    zombie = zombieHorde(num, "Zombie");
    for (int i = 0; i < num; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return (0);
}
