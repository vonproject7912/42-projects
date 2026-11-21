/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:48:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 19:14:10 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _Weapon(NULL), _name(name) {
}

// in the prototype: asks for a reference
void HumanB::setWeapon(Weapon &given_weapon)
{
    // ask for an address
    _Weapon = &given_weapon;
}

void HumanB::attack() const
{
    if (!_Weapon)
    {
        std::cout << _name << " has no weapon to attack with" << std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
