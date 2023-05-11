/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:17 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/20 10:51:15 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src.name) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = src;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  this->name = rhs.name;
  this->hitPoints = rhs.hitPoints;
  this->energyPoints = rhs.energyPoints;
  this->attackDamage = rhs.attackDamage;
  return (*this);
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap default destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " ask to make a high five!" << std::endl;
}