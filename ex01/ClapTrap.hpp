/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:57 by facetint          #+#    #+#             */
/*   Updated: 2024/10/23 15:48:58 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

private:
    std::string name;
    unsigned int hitPoint;
    unsigned int energyPoint;
    unsigned int attackDamage;
    ClapTrap();

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap& operator=(const ClapTrap& other);
    unsigned int getHitPoint() const;
    unsigned int getEnergyPoint() const;
    unsigned int getAttackDamage() const;
    std::string getName() const;
    void setName(std::string name);
    void setHitPoint(unsigned int hitPoint);
    void setEnergyPoint(unsigned int energyPoint);
    void setAttackDamage(unsigned int attackDamage);

};

#endif

