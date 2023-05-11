/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:32:35 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 17:42:09 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name),  hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name <<  " attacks " << target << " at " << this->attackDamage << " damage points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		if (amount > this->hitPoints)
			amount = this->hitPoints;
		this->hitPoints -= amount;
		std::cout << this->name << " takes " << amount << " damage points he has now " << this->hitPoints << " hit points !" << std::endl;
	}
	else
	{
		if (this->hitPoints <= 0)
			std::cout << this->name << " is already dead !" << std::endl;
		else
			std::cout << this->name << " is out of energy !" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0 && this->hitPoints < 100)
	{
		if (this->hitPoints + amount > 100)
			amount = 100 - this->hitPoints;
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << this->name << " has been repaired " << amount << " points ! He is now at " << this->hitPoints << " hit points !" << std::endl;
	}
	else
	{
		if (this->hitPoints <= 0)
			std::cout << this->name << " is already dead !" << std::endl;
		else if (this->energyPoints <= 0)
			std::cout << this->name << " is out of energy !" << std::endl;
		else
			std::cout << this->name << " is already at maximum hit points !" << std::endl;
	}
}