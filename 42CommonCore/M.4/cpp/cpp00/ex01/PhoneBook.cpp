/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:17:39 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/16 08:52:11 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->count = 0;
    this->index = 0;
}

int PhoneBook::readField(const std::string &quest, std::string &input) const
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
        return (1);
    Contacts[index].setFirstName(input);
    if (readField("Last Name: ", input))
        return (1);
    Contacts[index].setLastName(input);
    if (readField("Nickname: ", input))
        return (1);
    Contacts[index].setNickname(input);
    if (readField("Phone Number: ", input))
        return (1);
    Contacts[index].setPhoneNumber(input);
    if (readField("Darkest Secret: ", input))
        return (1);
    Contacts[index].setDarkestSecret(input);
    index = (index + 1) % 8;
    if (count < 8)
        count++;
    return (0);
}

int PhoneBook::searchContact() const
{
    int current;

    current = 0;
    if (count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return (0);
    }
    std::cout << std::setw(10) << "index" << "|" 
                << std::setw(10) << "first name" << "|"
                << std::setw(10) << "last name" << "|"
                << std::setw(10) << "nickname" << std::endl;
    while (current < count)
    {
        Contacts[current].displayRow(current);
        current++;
    }
    if (readIndex())
        return (1);
    return (0);
}

int PhoneBook::readIndex() const
{
    size_t i;
    int given_index;
    std::string tmp_str;

    i = 0;
    std::cout << "Please enter the index of a contact: ";
    if (!std::getline(std::cin, tmp_str))
        return (1);
    if (tmp_str.empty())
    {
        std::cout << "Empty input, please use SEARCH again." << std::endl;
        return (0);
    }
    while (i < tmp_str.size())
    {
        if (!std::isdigit(tmp_str[i]))
        {
            std::cout << "Incorrect input format, please use SEARCH again." << std::endl;
            return (0);
        }
        i++;
    }
    if (tmp_str.size() > 3)
    {
        std::cout << "Invalid input, please use SEARCH again." << std::endl;
        return (0);
    }
    given_index = std::atoi(tmp_str.c_str());
    if (given_index >= 0 && given_index < count)
    {
        Contacts[given_index].displayFull();
        return (0); 
    }
    std::cout << "Index out of range, please use SEARCH again." << std::endl;
    return (0);
}
