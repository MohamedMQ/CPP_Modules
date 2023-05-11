/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:33 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:01 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &cpy);
		~Fixed(void);
		
		void	operator=(Fixed const &cpy);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					Value;
		static const int	nbBits = 8;
};

#endif