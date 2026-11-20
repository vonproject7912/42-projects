/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:03:17 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 19:29:29 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// allocate my horde
Zombie* zombieHorde(int N, std::string name)
{
    int i;

    i = 0;
    if (N <= 0)
        return (NULL);
    Zombie *Horde = new Zombie[N];
    while (i < N)
    {
        Horde[i].setName(name);
        i++;
    }
    return (Horde);
}
