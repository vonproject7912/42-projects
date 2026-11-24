/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:43:02 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/24 23:21:31 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "Ahhh.. There is a little bit of an issue here." << std::endl;
}

void Harl::info()
{
    std::cout << "Gotta fix it please." << std::endl;
}

void Harl::warning()
{
    std::cout << "Fix it by 8pm, no question asked." << std::endl;
}

void Harl::error()
{
    std::cout << "Should've been fixed by now, you want problems ?" << std::endl;
}

void Harl::complain(std::string given_level)
{
    void (Harl::*level[4])(void);
    std::string name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    level[0] = &Harl::debug;
    level[1] = &Harl::info;
    level[2] = &Harl::warning;
    level[3] = &Harl::error;
    for (int i = 0; i < 4; i++)
    {
        if (name[i] == given_level)
         {
            (this->*level[i])();
            return ;
         }
    }
    std::cout << "Level not found.";
}
