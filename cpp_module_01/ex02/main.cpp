/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:18 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 09:52:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Adress string: " << &string << std::endl;
	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Adress stringPTR: " << stringPTR << std::endl;
	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Value stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	
	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Value string: " << string << std::endl;
	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << std::left << std::setfill(' ') << std::setw(20) << "Adress stringREF: " << stringREF << std::endl;
	
	return (0);
}