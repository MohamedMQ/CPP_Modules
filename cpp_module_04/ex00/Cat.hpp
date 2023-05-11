/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:31:29 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:32 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();
		Cat	&operator=(Cat const &rhs);
		void	makeSound() const;
};

#endif