/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:05:40 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:42 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const &src);
		virtual ~Ice();
		Ice &operator=(Ice const &rhs);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif