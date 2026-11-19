/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:58:48 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/19 20:26:29 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce() const;
};
    
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif