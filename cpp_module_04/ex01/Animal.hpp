/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:08:57 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:08:59 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string	type;
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();
		Animal	&operator=(Animal const &rhs);
		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif