/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:15:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:29 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &cpy);
		Fixed(int const &value);
		Fixed(float const &value);
		~Fixed(void);
		
		void	operator=(Fixed const &cpy);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int					Value;
		static const int	nbBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif