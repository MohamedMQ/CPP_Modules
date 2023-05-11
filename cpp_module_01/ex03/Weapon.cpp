/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:02:41 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 10:49:53 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type)
{
	std::cout << "Weapon " << this->type << " is created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->type << " is destroyed" << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType(void)
{
	return (this->type);
}