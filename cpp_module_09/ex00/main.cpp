/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:03:47 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/02 11:03:48 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	BitcoinExchange btcExchange;
	btcExchange.readCsvFile();
	btcExchange.readInputFile(av[1]);
	return (0);
}