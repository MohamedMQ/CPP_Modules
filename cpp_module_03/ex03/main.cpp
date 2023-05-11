/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:28 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 17:04:45 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	{
		DiamondTrap clap("Michel");
		clap.whoAmI();
		clap.attack("John");
		clap.takeDamage(1);
		clap.beRepaired(1);
		clap.highFivesGuys();
		clap.guardGate();
	}
	std::cout << "==========================" << std::endl;
	{
		DiamondTrap clap("Bob");
		std::cout << "==========================" << std::endl;
		DiamondTrap clap3(clap);
		clap.whoAmI();
		clap.attack("John");
		clap.takeDamage(1);
		clap.beRepaired(1);
		clap.highFivesGuys();
		clap.guardGate();
	}
}