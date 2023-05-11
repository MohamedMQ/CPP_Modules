/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:19:03 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/14 16:19:08 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed e;
	Fixed a2;
	Fixed const b2( Fixed( 5.05f ) * Fixed( 2 ) );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	std::cout << "(a > b) = " << (a > b) << std::endl;
	std::cout << "(a < b) = " << (a < b) << std::endl;
	std::cout << "(a >= b) = " << (a >= b) << std::endl;
	std::cout << "(a <= b) = " << (a <= b) << std::endl;
	std::cout << "(a == b) = " << (a == b) << std::endl;
	std::cout << "(a != b) = " << (a != b) << std::endl;
	std::cout << "(d == b) = " << (d == b) << std::endl;
	std::cout << "(d >= b) = " << (d >= b) << std::endl;
	std::cout << "(d <= b) = " << (d <= b) << std::endl;

	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << "------------------------------------Subject tests--------------------------------" << std::endl;

	std::cout << a2 << std::endl;
	std::cout << ++a2 << std::endl;
	std::cout << a2 << std::endl;
	std::cout << a2++ << std::endl;
	std::cout << a2 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << Fixed::max( a2, b2 ) << std::endl;
	std::cout << Fixed::min( a2, b2 ) << std::endl;

	return (0);
}