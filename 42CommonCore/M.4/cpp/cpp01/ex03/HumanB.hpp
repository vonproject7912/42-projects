/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:16:27 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 19:16:00 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <cstddef>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
    private:
        Weapon *_Weapon;
        std::string _name;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &given_weapon);
        void attack() const;
};

#endif