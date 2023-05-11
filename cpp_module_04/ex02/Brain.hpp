/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:07:09 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();
		
		Brain	&operator=(Brain const &rhs);
	private:
		std::string		_ideas[100];
};

#endif