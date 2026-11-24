/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 00:03:23 by vonpr             #+#    #+#             */
/*   Updated: 2026/11/24 21:38:02 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string file;
    std::string of_name;
    std::string::size_type i;
    std::string::size_type pos;

    // Arguments check
    if (ac != 4)
    {
        std::cerr << "Incorrect number of arguments: <file_name> <s1> <s2>" << std::endl;
        return (1);
    }
    s2 = av[3];
    s1 = av[2];
    file = av[1];
    if (s1.empty() || file.empty())
    {
        std::cerr << "Empty arguments, please try again." << std::endl;
        return (1);
    }
    
    // Open and link to the in file
    std::ifstream file_one;
    file_one.open(av[1]);
    if (!file_one.is_open())
    {
        std::cerr << "Failed to open the file: " << av[1] << std::endl;
        return (1);
    }
    
    // Open and link to the in file
    of_name = file + ".replace";
    std::ofstream file_two(of_name.c_str());
    if (!file_two.is_open())
    {
        std::cerr << "Failed to open the file: " << of_name << std::endl;
        return (1);
    }

    // Find and replace
    std::string line;
    while (std::getline(file_one, line))
    {
        pos = 0;
        while ((i = line.find(s1, pos)) != std::string::npos)
        {
            pos = i + s2.size();
            line.erase(i, s1.size());
            line.insert(i, s2);
        }
        file_two << line;
        if (!file_one.eof())
            file_two << std::endl;
    }
    return (0);
}
