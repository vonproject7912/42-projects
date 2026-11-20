/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:48 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/20 17:32:13 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        int _size;
        std::string _name;
        Zombie(std::string name);
        ~Zombie();
    public:
        void announce() const;
        Zombie* zombieHorde( int N, std::string name );
};

#endif