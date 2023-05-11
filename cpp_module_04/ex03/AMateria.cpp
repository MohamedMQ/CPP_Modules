/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:13 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:14 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const & type) {
	this->_type = type;
}

AMateria::AMateria(AMateria const &src) {
	*this = src;
}

AMateria::~AMateria(void) {}

AMateria &AMateria::operator=(AMateria const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* " << this->_type << " casts " << this->_type << " on " << target.getName() << " *" << std::endl;
}

