/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:51 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();
		Dog	&operator=(Dog const &rhs);
		void	makeSound() const;
	private:
		Brain *_brain;
};

#endif