/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:16:43 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/13 12:09:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    static std::string truncate(const std::string &str);
    
    public:
    void setFirstName(const std::string &NewFirstName);
    void setLastName(const std::string &NewLastName);
    void setNickname(const std::string &NewNickname);
    void setPhoneNumber(const std::string &NewPhoneNumber);
    void setDarkestSecret(const std::string &NewDarkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    void displayRow(int index) const;
    void displayFull() const;
};

#endif