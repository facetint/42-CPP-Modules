/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:10:24 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 20:19:11 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl h1;

    h1.complain("debug");
    h1.complain("info");
    h1.complain("error");
    h1.complain("warning");
}
