/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:10:24 by facetint          #+#    #+#             */
/*   Updated: 2024/10/10 23:27:31 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {

    Harl harl;

    if (ac == 2 && (std::string(av[1]) == "DEBUG" ||
                    std::string(av[1]) == "INFO" ||
                    std::string(av[1]) == "WARNING" ||
                    std::string(av[1]) == "ERROR")) {
        harl.complain(av[1]);
    }
    else
    {
        std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    }
    return 0;
}
