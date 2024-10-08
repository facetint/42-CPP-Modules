/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:34:21 by facetint          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:22 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);
};
Zombie* zombieHorde(int N, std::string name);

#endif
