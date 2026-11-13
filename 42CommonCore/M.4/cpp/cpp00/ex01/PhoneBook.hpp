/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:17:43 by mosriji           #+#    #+#             */
/*   Updated: 2026/11/13 13:25:05 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <cctype>
#include <iostream>
#include "Contact.hpp"

class PhoneBook 
{
    private:
    int count;
    int index;
    Contact Contacts[8];
    int readField(const std::string &quest, std::string &input);
    
    public:
    PhoneBook();
    int addContact();
};

#endif