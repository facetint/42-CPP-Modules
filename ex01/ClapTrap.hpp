/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:57 by facetint          #+#    #+#             */
/*   Updated: 2024/10/30 23:54:54 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>

# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define WHITE_COLOR "\x1b[38;2;255;255;255;01m"

class ClapTrap
{
  private:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;

  public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap &operator=(const ClapTrap &other);
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDamage() const;
	std::string getName() const;
	void setName(std::string name);
	void setHitPoint(unsigned int hitPoint);
	void setEnergyPoint(unsigned int energyPoint);
	void setAttackDamage(unsigned int attackDamage);
	void displayStats() const;
};

#endif
