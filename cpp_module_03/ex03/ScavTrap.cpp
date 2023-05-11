/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/20 10:51:18 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src.name) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  this->name = rhs.name;
  this->hitPoints = rhs.hitPoints;
  this->energyPoints = rhs.energyPoints;
  this->attackDamage = rhs.attackDamage;
  return (*this);
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name <<  " attacks " << target << " at " << this->attackDamage << " damage points" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << this->name << " enter in Gate Keeper mode !" << std::endl;
}