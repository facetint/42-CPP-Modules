/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:34 by facetint          #+#    #+#             */
/*   Updated: 2024/11/10 23:23:13 by fatmanurcet      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);
	void highFivesGuys(void);
};

#endif