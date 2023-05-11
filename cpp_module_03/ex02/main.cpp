/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:32:53 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/18 13:22:42 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap clap("Michel");
	FragTrap clap2("Bob");
	FragTrap clap3;
	FragTrap clap4(clap);

	clap3 = clap;
	clap2.highFivesGuys();
	clap2.beRepaired(1);
	clap2.takeDamage(10);
	clap2.beRepaired(1);
	clap2.attack("Michel");
	clap.takeDamage(30);
	clap2.attack("Michel");
	clap.takeDamage(30);
	clap2.attack("Michel");
	clap.takeDamage(30);
	clap.takeDamage(30);
}