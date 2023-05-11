/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:11:48 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/12 14:11:49 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::print_elem(std::string elem)
{
	if (elem.size() < 11)
	{
		for (unsigned long i = 0; i < 10 - elem.size(); i++)
			std::cout << " ";
		std::cout << elem;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << (char)elem[i];
		std::cout << ".";
	}
	std::cout << "|";
}

void	Phonebook::print_contact(int index)
{
	std::cout << "|";
	std::cout << std::right << std::setfill (' ') << std::setw (11) << "index|";
	std::cout << std::right << std::setfill (' ') << std::setw (11) << "first name|";
	std::cout << std::right << std::setfill (' ') << std::setw (11) << "last name|";
	std::cout << std::right << std::setfill (' ') << std::setw (11) << "nick name|" << std::endl;
	for (int i = 0; i < 8 && i < index; i++)
	{
		std::cout << "|" << std::right << std::setfill (' ') << std::setw (10) << (char)(i + 48) << "|";
		print_elem(this->contacts[i].getFirstName());
		print_elem(this->contacts[i].getLastName());
		print_elem(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	Phonebook::print_one_contact(int index)
{
	std::cout << "First name: " << this->contacts[index % 8].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index % 8].getLastName() << std::endl;
	std::cout << "Nick name: " << this->contacts[index % 8].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index % 8].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index % 8].getDarkestSecret() << std::endl;
}

int Phonebook::search_contact(int index)
{
	std::string	line;

	if(index == 0)
	{
		std::cout << "No contact found" << std::endl;
		return (0);
	}
	print_contact(index);
	std::cout << "Enter index: ";
	while (std::getline(std::cin, line))
	{
		if (!line.size())
			std::cout << "Enter index: ";
		else if (line.size() != 1 || line[0] < '0' || line[0] > '8' || line[0] > (index + 48 - 1))
		{
			std::cout << "Invalid index" << std::endl;
			std::cout << "Enter index: ";
		}
		else
		{
			print_one_contact(line[0] - '0');
			return (0);
		}
	}
	if (std::cin.eof())
		return (1);
	print_one_contact(line[0] - '0');
	return (0);
}

int Phonebook::add_contact(int index)
{
	std::string line;

	std::cout << "Enter first name: ";
	while (std::getline(std::cin, line) && line.empty())
		std::cout << "Enter first name: ";
	if (std::cin.eof())
		return (0);
	this->contacts[index].setFirstName(line);
		std::cout << "Enter last name: ";
	while (std::getline(std::cin, line) && line.empty())
		std::cout << "Enter last name: ";
	if (std::cin.eof())
		return (0);
	this->contacts[index].setLastName(line);
		std::cout << "Enter nick name: ";
	while (std::getline(std::cin, line) && line.empty())
		std::cout << "Enter nick name: ";
	if (std::cin.eof())
		return (0);
	this->contacts[index].setNickname(line);
		std::cout << "Enter phone number: ";
	while (std::getline(std::cin, line) && line.empty())
		std::cout << "Enter phone number: ";
	if (std::cin.eof())
		return (0);
	this->contacts[index].setPhoneNumber(line);
		std::cout << "Enter darkest secret: ";
	while (std::getline(std::cin, line) && line.empty())
		std::cout << "Enter darkest secret: ";
	if (std::cin.eof())
		return (0);
	this->contacts[index].setDarkestSecret(line);
	return (1);
}
