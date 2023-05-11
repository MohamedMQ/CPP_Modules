/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:03:34 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/03 18:00:22 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
    *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this != &obj)
		this->_dataBase = obj._dataBase;
	return (*this);
}

bool BitcoinExchange::validateNum(std::string const & strNum) {
	float number;
	std::stringstream sstream(strNum);

	if (std::isspace(strNum[0])) {
		std::cout << "Error: bad input => " << strNum << "\n";
		return 0;
    }
	if (!(sstream >> number) || !sstream.eof()) {
		std::cout << "Error: bad input => " << strNum << "\n";
		return 0;
	}
	if (number > 1000) {
		std::cout << "Error: too large a number\n";
		return 0;
	} else if (number < 0) {
		std::cout << "Error: not a positive number\n";
		return 0;
	}
	return 1;
}

int BitcoinExchange::validateDate(std::string const &date) {
	int		i = -1;

	if (date.length() != 10) {
		std::cout << "Error: bad input => " << date << "\n";
		return 0;
	}
	while (++i < 10) {
		if ((i != 4 && i != 7 && !isdigit(date[i]))
		|| ((i == 4 || i == 7) && date[i] != '-')) {
			std::cout << "Error: bad input => " << date << "\n";
			return 0;
		}
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if ((year < 2009)
	|| ( month < 1 || month > 12)
	|| (day < 1)) {
		std::cout << "Error: bad input => " << date << "\n";
		return 0;
	}
	if (month == 2) {
		if (!(year % 4) && ((year % 100) || !(year % 400))) {
			if (day > 29) {
				std::cout << "Error: bad input => " << date << "\n";
				return 0;
			}
		} else {
			if (day > 28) {
				std::cout << "Error: bad input => " << date << "\n";
				return 0;
			}
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			std::cout << "Error: bad input => " << date << "\n";
			return 0;
		}
	} else {
		if (day > 31) {
			std::cout << "Error: bad input => " << date << "\n";
			return 0;
		}
	}
	return 1;
}

void BitcoinExchange::checkInputLine(std::string const & readLine) {
	size_t pipPos = readLine.find(" | ");

	// std::cout << "|||" << readLine << "|||\n";
	if (pipPos == std::string::npos || pipPos + 3 >= readLine.size()) {
		std::cerr << "Error: bad input => " << readLine << "\n";
		return ;
	}
	std::string date = readLine.substr(0, pipPos);
	std::string num = readLine.substr(pipPos + 3);
	if (!validateDate(date))
		return ;
	if (!validateNum(num))
		return ;
	float number = atof(num.c_str());
	if (number != number) {
		std::cerr << "Error: bad input => " << readLine << "\n";
		return ;
	}
	std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
	if (it == _dataBase.begin() && date != it->first) {
		std::cerr << "Error: bad input => " << readLine << "\n";
		return ;
	}
    if (date != it->first && it != _dataBase.begin())
        it--;
    std::cout << date << " => " << num << " = " << it->second * number << "\n";
}

void	BitcoinExchange::readInputFile(std::string const &inputFile) {
	std::ifstream readFile(inputFile.c_str());
	std::string readLine;

	if (!readFile) {
		std::cerr << "Error: could not open " << inputFile << " file\n";
		exit(1);
	}
	getline(readFile, readLine);
	if (readLine.compare("date | value")) {
		readFile.close();
		std::cerr << "Error: Incorrect " << inputFile << " header format\n";
		exit(1);
	}
	while (getline(readFile, readLine)) {
		if (!readLine.size())
			continue ;
		checkInputLine(readLine);
	}
	readFile.close();
}

void	BitcoinExchange::readCsvLine(std::string const & readLine) {
	std::string date, strNumber;
	size_t comaPos;
	float number;

	comaPos = readLine.find(",");
	date = readLine.substr(0, comaPos);
	strNumber = readLine.substr(comaPos + 1);
	number = atof(strNumber.c_str());
	_dataBase[date] = number;
}

void	BitcoinExchange::readCsvFile() {
	std::ifstream readFile("data.csv");
	std::string readLine;

	if (!readFile) {
		std::cerr << "Error: could not open 'data.csv' file\n";
		exit(1);
	}
	getline(readFile, readLine);
	while (getline(readFile, readLine))
		readCsvLine(readLine);
	readFile.close();
}