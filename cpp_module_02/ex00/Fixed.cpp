/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:05 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/14 16:16:58 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : Value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	this->Value = cpy.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(Fixed const &cpy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->Value = cpy.getRawBits();
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->Value;
}

void Fixed::setRawBits(int const raw) {
	this->Value = raw;
}
