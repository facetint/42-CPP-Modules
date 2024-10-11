/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 05:05:59 by facetint          #+#    #+#             */
/*   Updated: 2024/10/11 05:06:00 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	entrance(void)
{
	std::cout << PURPLE_COLOR << std::endl;
	std::cout << "$------------------------------------------------$" << std::endl;
	std::cout << "$                                                $" << std::endl;
	std::cout << "$       Welcome to my wonderful phone book 🖐     $" << std::endl;
	std::cout << "$                                                $" << std::endl;
	std::cout << "$       Enter a command: (ADD, SEARCH, EXIT)     $" << std::endl;
	std::cout << "$                                                $" << std::endl;
	std::cout << "$ ADD :    Adds a new contact to the phone book  $" << std::endl;
	std::cout << "$ SEARCH : Allows you to search the phone book   $" << std::endl;
	std::cout << "$ EXIT :   Allows you to exit the program        $" << std::endl;
	std::cout << "$------------------------------------------------$" << std::endl;
	std::cout << RESET << std::endl;
} 
int	main(void)
{
	PhoneBook	input;

	std::string str;
	while (1)
	{
		entrance();
		str = get_input();
		if (str == "EXIT")
			break ;
		else if (str == "ADD")
			input.addContact();
		else if (str == "SEARCH")
			input.searchContact();
		else
			std::cout  << RED_COLOR << "Invalid command" << RESET << std::endl;
	}

	return (0);
}