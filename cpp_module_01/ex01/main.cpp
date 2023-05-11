/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:28:37 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/13 09:35:37 by mmaqbour         ###   ########.fr       */
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
		int		N = 10;
		Zombie	*horde = zombieHorde(N, "youness");

		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	
	return (0);
}