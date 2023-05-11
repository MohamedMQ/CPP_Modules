/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:33:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 17:44:38 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("ScavTrap") {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src.name) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " enter in Gate Keeper mode !" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy" << std::endl;
		return ;
	}
	this->energyPoints --;
	std::cout << "ScavTrap " << this->name <<  " attacks " << target << " at " << this->attackDamage << " damage points" << std::endl;
}