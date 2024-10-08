/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:34:24 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:25 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie[i].setName(name);
    }
    return (zombie);
}
