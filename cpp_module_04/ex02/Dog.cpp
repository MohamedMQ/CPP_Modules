/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:53 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:55 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(Dog const &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->type = rhs.type;
	*this->_brain = *rhs._brain;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Wouuuuuuuuuuuuuuuuuuaaaaaf..." << std::endl;
}