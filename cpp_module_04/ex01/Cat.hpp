/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:08:38 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:08:40 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat: public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();
		Cat	&operator=(Cat const &rhs);
		void	makeSound() const;
};
#endif
