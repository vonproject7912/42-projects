/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:51:05 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/21 19:20:11 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        // create a weapon
        Weapon club = Weapon("crude spiked club");
        // create a human with a ref that points to club
        HumanA bob("Bob", club);
        // print attack and weapon type
        bob.attack();
        // change the actual weapon object
        club.setType("some other type of club");
        // print again the attack
        bob.attack();
    }
    {
        // create a weapon
        Weapon club = Weapon("crude spiked club");
        // create a humain with a pointer that takes a ref
        HumanB jim("Jim");
        // takes the object created and not a copy
        jim.setWeapon(club);
        // print the attack: humain + weapon
        jim.attack();
        // change the type of the object weapon created
        club.setType("some other type of club");
        // print the attack again
        jim.attack();
    }
    return 0;
}
