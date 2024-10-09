/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:10:24 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 18:54:04 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {

    std::string level;
    std::cout << "Please enter the level of complaint (debug/info/warning/error): ";
    std::cin >> level;
    Harl harl;
    harl.complain(level);
    return 0;
}
