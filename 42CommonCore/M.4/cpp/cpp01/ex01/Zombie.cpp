/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:15:43 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 19:29:16 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie(): _name(""){
}

// destructor
Zombie::~Zombie()
{
    std::cout << "Dropped dead..." << std::endl;
}

// set the name
void Zombie::setName(std::string name)
{
    this->_name = name;
}

// annonce itself
void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
