/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:52:30 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 18:47:46 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string given_weapon): _type(given_weapon){
}

const std::string &Weapon::getType() const
{
    return (_type);
}

void Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}
