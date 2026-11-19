/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:48:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/19 20:06:19 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string given_name;
    std::cout << "Give the zombies a name: ";
    if (!getline(std::cin, given_name) || given_name.empty())
        return (1);
    Zombie *heapZombie = newZombie(given_name);
    heapZombie->announce();
    randomChump(given_name);
    delete heapZombie;
    return (0);
}
