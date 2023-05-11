/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:32:07 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/19 17:59:48 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap clap("Michel");
	ScavTrap clap2("Bob");
	ScavTrap clap3;
	ScavTrap clap4(clap);

	clap3 = clap;
	clap2.guardGate();
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.takeDamage(10);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.attack("Michel");
	clap.takeDamage(20);
	clap2.attack("Michel");
	clap.takeDamage(20);
	clap2.attack("Michel");
	clap.takeDamage(20);
	clap2.attack("Michel");
	clap.takeDamage(20);
	clap2.attack("Michel");
	clap.takeDamage(20);
	clap2.attack("Michel");
	clap.takeDamage(20);
}