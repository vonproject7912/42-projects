/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:48:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 19:24:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL), _name(name) {
}

// in the prototype: asks for a reference
void HumanB::setWeapon(Weapon &given_weapon)
{
    // store the address of the weapon
    _weapon = &given_weapon;
}

void HumanB::attack() const
{
    if (!_weapon)
    {
        std::cout << _name << " has no weapon to attack with" << std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
