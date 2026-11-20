/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:15:43 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 17:31:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name): _name(""){
}

// destructor
Zombie::~Zombie()
{
    std::cout << "Dropped dead..." << std::endl;
}

// annonce itself
void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
