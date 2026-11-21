/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:11:17 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 19:09:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &given_weapon): _Weapon(given_weapon), _name(name) {   
}

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
