/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:16:43 by mosriji           #+#    #+#             */
/*   Updated: 2026/10/29 17:41:46 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cctype>
#include <iostream>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    
    public:
    void setFirstName(std::string NewFirstName)
    {
        // "this" is a pointer to the current contact
        this->firstName = NewFirstName;
    }
    void setLastName(std::string NewLastName)
    {
        this->lastName = NewLastName;
    }
    void setNickname(std::string NewNickname)
    {
        this->nickname = NewNickname;
    }
    void setPhoneNumber(std::string NewPhoneNumber)
    {
        this->phoneNumber = NewPhoneNumber;
    }
    void setDarkestSecret(std::string NewDarkestSecret)
    {
        this->darkestSecret = NewDarkestSecret;
    }
};

#endif