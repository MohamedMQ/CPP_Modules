/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:49:37 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/11 13:03:43 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else {
		std::cerr << "Error\nUsage: ./convert <arg>\n";
		return -1;
	}
	return 0;
}
