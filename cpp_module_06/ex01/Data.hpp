/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/10 16:50:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data {
    std::string name;
    std::string surname;
    std::string username;

    void displayInfo() {
        std::string fullName;

        fullName = name + " " + surname;
        std::cout << "My full name is " << fullName
        << ".My username in 42 Network is "
        << username << std::endl;
    }
};

#endif