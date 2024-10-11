/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:41:03 by facetint          #+#    #+#             */
/*   Updated: 2024/10/10 21:10:41 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
  private:
    std::string _type;

  public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType(void) const;
    void setType(std::string type);
};

#endif