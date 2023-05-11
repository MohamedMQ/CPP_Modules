/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:05:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:50 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const &src);
		virtual ~Cure();
		Cure &operator=(Cure const &rhs);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif