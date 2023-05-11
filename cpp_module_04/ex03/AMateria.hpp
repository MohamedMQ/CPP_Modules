/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria;
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string		_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		virtual ~AMateria();
		AMateria &operator=(AMateria const &rhs);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif