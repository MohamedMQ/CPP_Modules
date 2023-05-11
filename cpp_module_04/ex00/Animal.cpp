/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:31:45 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Random Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Miafcuiannnnnn.... !!" << std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}