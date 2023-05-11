/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:15:01 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:20 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : Value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const &value) {
	this->Value = value << this->nbBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &value) {
	this->Value = roundf(value * (1 << this->nbBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->Value = other.getRawBits();
}

std::ostream& operator<<(std::ostream &out, Fixed const &value) {
	out << value.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const {
	return this->Value;
}

void Fixed::setRawBits(int const raw) {
	this->Value = raw;
}

int Fixed::toInt(void) const {
	return (this->Value >> this->nbBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->Value / (float)(1 << this->nbBits));
}
