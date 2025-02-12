/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:05:53 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:55 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(std::string const & type): AMateria(type) {}

Cure::Cure(Cure const &src): AMateria(src) {
	*this = src;
}

Cure::~Cure(void) {}

Cure &Cure::operator=(Cure const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
