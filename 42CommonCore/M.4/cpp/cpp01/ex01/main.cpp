/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 19:25:53 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int size;
    Zombie *Walkers;
    std::string given_size;
    std::string given_name;
    
    std::cout << "Give a name to your zombiess~ ";
    if (!std::getline(std::cin, given_name) || given_name.empty())
        return (1);
    std::cout << "Enter the size for the Zombie Horde: ";
    if (!std::getline(std::cin, given_size) || given_size.empty())
        return (1);
    size = std::atoi(given_size.c_str());
    Walkers = zombieHorde(size, given_name);
    delete Walkers[];
    return (0);
}
