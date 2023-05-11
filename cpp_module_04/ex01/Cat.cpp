/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:08:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:08:44 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = rhs.type;
	*this->_brain = *rhs._brain;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaaaaaaaaaaaaaaaaaaaaaaaaaaooouuu !" << std::endl;
}
