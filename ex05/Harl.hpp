/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:51:15 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 20:19:23 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
public:
    Harl();
    ~Harl();
    void complain(std::string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

};

#endif