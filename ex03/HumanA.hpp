/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:43:00 by facetint          #+#    #+#             */
/*   Updated: 2024/10/04 06:02:02 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class   HumanA{

    private:
        std::string _name;
        Weapon &_weapon;
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack(void);
};

