/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:31:20 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:22 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();
		Dog	&operator=(Dog const &rhs);
		void	makeSound() const;
};

#endif