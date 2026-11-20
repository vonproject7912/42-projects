/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:48 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 19:27:15 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();
        void announce() const;
        void setName(std::string name);
};
    
Zombie* zombieHorde(int N, std::string name);

#endif