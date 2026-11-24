/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:51:05 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/25 00:53:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// given mid main
int main()
{
    {
        // create a weapon: the club 
        Weapon club = Weapon("crude spiked club");
        // create a human with a ref that points to the club
        HumanA bob("Bob", club);
        // print the attack: humain + weapon
        bob.attack();
        // change the actual weapon object: it's type
        club.setType("some other type of club");
        // prints the attack again
        bob.attack();
    }
    {
        // create a weapon
        Weapon club = Weapon("crude spiked club");
        // create a human with no weapon yet (pointer is NULL)
        HumanB jim("Jim");
        // takes the object created and not a copy => store its address
        jim.setWeapon(club);
        // print the attack: humain + weapon
        jim.attack();
        // change the type of the object weapon created
        club.setType("some other type of club");
        // prints the attack again
        jim.attack();
    }
    return 0;
}
