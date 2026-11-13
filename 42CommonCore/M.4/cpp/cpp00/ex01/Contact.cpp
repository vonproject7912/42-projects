/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:16:37 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/13 12:13:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::truncate(const std::string &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return str;
}

// setters
void Contact::setFirstName(const std::string &newFirstName)
{
    // "this" is a pointer to the current contact
    this->firstName = newFirstName;
}
void Contact::setLastName(const std::string &newLastName)
{
    this->lastName = newLastName;
}
void Contact::setNickname(const std::string &newNickname)
{
    this->nickname = newNickname;
}
void Contact::setPhoneNumber(const std::string &newPhoneNumber)
{
    this->phoneNumber = newPhoneNumber;
}
void Contact::setDarkestSecret(const std::string &newDarkestSecret)
{
    this->darkestSecret = newDarkestSecret;
}
// getters
std::string Contact::getFirstName() const 
{
    return (firstName);
}
std::string Contact::getLastName() const 
{
    return (lastName);
}
std::string Contact::getNickname() const 
{
    return (nickname);
}
std::string Contact::getPhoneNumber() const 
{
    return (phoneNumber);
}
std::string Contact::getDarkestSecret() const 
{
    return (darkestSecret);
}
// display
void Contact::displayRow(int index) const {
    std::cout << std::setw(10) << index << "|"
                << std::setw(10) << truncate(firstName) << "|"
                << std::setw(10) << truncate(lastName) << "|"
                << std::setw(10) << truncate(nickname) << std::endl;
}
void Contact::displayFull() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
