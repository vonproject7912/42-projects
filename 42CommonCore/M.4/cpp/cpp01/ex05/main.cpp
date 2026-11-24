/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:30:02 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/24 23:20:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl call;
    
    std::cout << "Test for debug call: ";
    call.complain("DEBUG");
    std::cout << std::endl;
    std::cout << "Test for info call: ";
    call.complain("INFO");
    std::cout << std::endl;
    std::cout << "Test for warning call: ";
    call.complain("WARNING"); 
    std::cout << std::endl;
    std::cout << "Test for error call: ";
    call.complain("ERROR");
    std::cout << std::endl;
    std::cout << "Test for unknown call: ";
    call.complain("feur");
    std::cout << std::endl;
}
