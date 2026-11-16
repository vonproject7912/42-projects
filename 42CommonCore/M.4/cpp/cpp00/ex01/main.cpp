/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:16:50 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/16 16:56:23 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main ()
{
    std::string line;
    PhoneBook repertoire;
    
    while (1)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, line))
            return (0);
        else if (line == "ADD")
        {
            if (repertoire.addContact())
                return (0);
        }
        else if (line == "SEARCH")
        {
            if (repertoire.searchContact())
                return (0);
        }
        else if (line == "EXIT")
            return (0);
        else
            std::cout << "Command doesn't exist, please try again" << std::endl;
    }
}
