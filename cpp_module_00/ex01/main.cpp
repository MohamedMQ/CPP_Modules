/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:11:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/12 14:11:15 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>

int	add(Phonebook *phonebook, int *index)
{
	if (!phonebook->add_contact((*index) % 8))
		return (1);
	if ((*index) + 1 < 16)
		(*index)++;
	else
		(*index) = 8;
	return (0);
}

int main(void)
{
	Phonebook	phonebook;
	std::string	line;
	int			index;

	std::cout << "> ";
	index = 0;
	while (std::getline(std::cin, line))
	{	
		if (line == "EXIT")
			break ;
		if (line == "ADD")
			if (add(&phonebook, &index))
				break ;
		if (line == "SEARCH")
			if (phonebook.search_contact(index))
				break ;
		std::cout << "> ";
	}
	if (line != "EXIT")
		std::cout << std::endl;
	return (0);
}