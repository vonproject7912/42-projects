/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:53:04 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 16:05:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        Weapon &WeaponA;
        std::string _name;
    public:
        void attack() const;
        HumanA(std::string name, Weapon &given_weapon);
};

#endif