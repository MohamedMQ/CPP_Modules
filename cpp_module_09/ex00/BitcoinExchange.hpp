/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:03:40 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/02 11:03:42 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <sstream>
# include <fstream>
# include <cstdlib>
# include <iostream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _dataBase;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		bool	validateNum(std::string const &strNum);
		int		validateDate(std::string const  &date);
		void	checkInputLine(std::string const &line);
		void	readCsvFile();
		void	readCsvLine(std::string const &readLine);
		void	readInputFile(std::string const &inputFile);
};

#endif
