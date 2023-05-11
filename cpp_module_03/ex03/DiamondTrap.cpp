/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:54 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/20 11:45:56 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
  std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
  this->hitPoints = FragTrap::hitPoints;
  this->energyPoints = ScavTrap::energyPoints;
  this->attackDamage = FragTrap::attackDamage;
  std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = src;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  this->name = rhs.name;
  this->hitPoints = rhs.hitPoints;
  this->energyPoints = rhs.energyPoints;
  this->attackDamage = rhs.attackDamage;
  return (*this);
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "I am the DiamondTrap " << this->name << " and I inherit from the ClapTrap " << ClapTrap::name << "!" << std::endl;
}