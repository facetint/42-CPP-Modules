/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:29 by facetint          #+#    #+#             */
/*   Updated: 2024/11/10 23:21:07 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string _name;
  public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);
	void whoAmI();
	std::string getDiamondName() const;
	void setDiamondName(std::string name);
};
#endif
