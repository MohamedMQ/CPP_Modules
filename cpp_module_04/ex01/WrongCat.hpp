/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:38 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:07:39 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		virtual ~WrongCat();
		WrongCat	&operator=(WrongCat const &rhs);
		void	makeSound() const;
};

#endif