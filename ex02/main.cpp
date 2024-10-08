/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:58:24 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:58:27 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "$-----------------------------------------$" << std::endl;
    std::cout << "Memory Address of str: " << &str << std::endl;
    std::cout << "Memory Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory Address of stringREF: " << &stringREF << std::endl;
    std::cout << "-------*********-------********------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Value of str variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
    std::cout << "$------------------------------------------$" << std::endl;

}
