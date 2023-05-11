/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:28:05 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 09:34:58 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int	main(void)
{
	{
		Zombie mohamed("mohamed");
		mohamed.announce();
	}

	std::cout << "----------------------" << std::endl;
	
	{
		Zombie *rida;

		rida = newZombie("rida");
		rida->announce();
		delete (rida);
	}
	
	std::cout << "----------------------" << std::endl;
	
	randomChump("ayoub");
	
	return (0);
}