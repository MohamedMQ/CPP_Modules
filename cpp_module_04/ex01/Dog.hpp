/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:08:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:08:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();
		Dog	&operator=(Dog const &rhs);
		void	makeSound() const;
};

#endif