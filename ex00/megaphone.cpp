/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:49:53 by fatmanurcet       #+#    #+#             */
/*   Updated: 2024/10/11 04:14:08 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string input;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			input = av[i];
			for (size_t i = 0; i < input.length(); i++)
				std::cout << (char)std::toupper(input[i]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
