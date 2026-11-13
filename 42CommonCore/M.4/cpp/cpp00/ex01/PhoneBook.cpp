/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:17:39 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/13 13:25:57 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->count = 0;
    this->index = 0;
}

int PhoneBook::readField(const std::string &quest, std::string &input)
{
    while (1)
    {
        std::cout << quest;
        if (!std::getline(std::cin, input))
            return (1);
        if (input.empty())
            std::cout << "Field cannot be empty." << std::endl;
        else
            break;
    }
    return (0);
}

int PhoneBook::addContact()
{
    std::string input;
    
    if (readField("First Name: ", input))
        return (1) ;
    Contacts[index].setFirstName(input);
    if (readField("Last Name: ", input))
        return (1) ;
    Contacts[index].setLastName(input);
    if (readField("Nickname: ", input))
        return (1) ;
    Contacts[index].setNickname(input);
    if (readField("Phone Number: ", input))
        return (1) ;
    Contacts[index].setPhoneNumber(input);
    if (readField("Darkest Secret: ", input))
        return (1) ;
    Contacts[index].setDarkestSecret(input);
    index = (index + 1) % 8;
    if (count < 8)
        count++;
    return (0);
}
