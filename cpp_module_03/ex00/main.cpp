/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:31:44 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 17:48:55 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap clap("Michel");
	ClapTrap clap2("Bob");
	ClapTrap clap3("John");
	ClapTrap clap4(clap);
	
	ClapTrap clap5;
	clap5 = clap;

	std::cout << "-----------Test 1-----------" << std::endl << std::endl;
	
	clap.attack("Bob");
	clap.takeDamage(10);
	clap.beRepaired(10);

	std::cout << "-----------Test 2-----------" << std::endl << std::endl;

	clap2.attack("Michel");
	clap2.takeDamage(5);
	clap2.beRepaired(5);

	std::cout << "-----------Test 3-----------" << std::endl << std::endl;
	
	clap3.attack("Michel");
	clap3.attack("Michel");
	clap3.attack("Michel");
	clap3.beRepaired(1);
	clap3.beRepaired(1);
	clap3.beRepaired(1);
}