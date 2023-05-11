/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:49:57 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/12 11:05:25 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
    *this = obj;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj) {
	(void)obj;
    return (*this);
}

void ScalarConverter::convert(std::string arg) {
    if (checkIfIsInt(arg))
		convertIfInt(arg);
	else if (checkIfIsChar(arg))
        convertIfChar(arg);
	else if (checkIfIsFloat(arg))
		convertIfFloat(arg);
	else if (checkIfIsDouble(arg))
		convertIfDouble(arg);
	else
		convertToString();
}

int ScalarConverter::checkIfIsInt(std::string arg) {
    int	j = 0;

	while (arg[j] && arg[j] == ' ')
		j++;
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	while (arg[j] >= '0' && arg[j] <= '9')
		j++;
	if (arg[j] == '\0' && j > 0 && arg[j - 1] >= '0' && arg[j - 1] <= '9')
		return 1;
	return 0;
}

int ScalarConverter::checkIfIsChar(std::string arg) {
    if (arg.size() && arg.size() == 1)
		return 1;
	return 0;
}

int ScalarConverter::checkIfIsFloat(std::string arg) {
	int	j = 0;

	if (arg == "nanf" || arg == "-inff" || arg == "+inff")
		return 1;
	while (arg[j] && arg[j] == ' ')
		j++;
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	while (arg[j] >= '0' && arg[j] <= '9')
		j++;
	if (arg[j] == '.' && j > 0 && arg[j - 1] >= '0' && arg[j - 1] <= '9')
		j++;
	else
		return 0;
	while (arg[j] >= '0' && arg[j] <= '9')
		j++;
	if (arg[j] == 'f' && j > 0 && arg[j - 1] != '.')
		j++;
	else
		return 0;
	if (arg[j] == '\0')
		return 1;
	return 0;
}

int ScalarConverter::checkIfIsDouble(std::string arg) {
	int	j = 0;

	if (arg == "nan" || arg == "-inf" || arg == "+inf")
		return 1;
	while (arg[j] && arg[j] == ' ')
		j++;
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	while (arg[j] >= '0' && arg[j] <= '9')
		j++;
	if (arg[j] == '.' && j > 0 && arg[j - 1] >= '0' && arg[j - 1] <= '9')
		j++;
	else
		return 0;
	while (arg[j] >= '0' && arg[j] <= '9')
		j++;
	if (arg[j] == '\0')
		return 1;
	return 0;
}

void ScalarConverter::convertIfInt(std::string arg) {
    long	num;
	double num1;
	std::stringstream str;

    num = std::strtol(arg.c_str(), 0, 10);
	str << arg;
	str >> num1;
	if (num >= 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	if (num <= 2147483647 && num >= -2147483648)
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	else
		std::cout << "int: impossible\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num1) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num1) << std::endl;
}

void ScalarConverter::convertIfChar(std::string arg) {
    char	ch;

    ch = arg.at(0);
	std::cout << "char: '" << ch << "'\n";
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(ch) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(ch) << std::endl;
}

void ScalarConverter::convertIfFloat(std::string arg) {
	if (convertFloDouPsLi(arg, 'f'))
        return;
	else
        printResultFlDo(arg);
}

void ScalarConverter::convertIfDouble(std::string arg) {
    if (convertFloDouPsLi(arg, 'd'))
        return;
    else
        printResultFlDo(arg);
}

int ScalarConverter::convertFloDouPsLi(std::string arg, char c) {
    if ((arg == "+inf" && c == 'd')
        || (arg == "+inff" && c == 'f')) {
		std::cout << "char: Non displayable\n"
		<< "int: impossible\n"
		<< "float: +inff\n"
		<< "double: +inf\n";
		return 1;
	} else if ((arg == "-inf" && c == 'd')
        || (arg == "-inff" && c == 'f')) {
		std::cout << "char: Non displayable\n"
		<< "int: impossible\n"
		<< "float: -inff\n"
		<< "double: -inf\n";
		return 1;
	} else if ((arg == "nan" && c == 'd')
        || (arg == "nanf" && c == 'f')) {
		std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: nanf\n"
		<< "double: nan\n";
		return 1;
	}
    return 0;
}

void ScalarConverter::printResultFlDo(std::string arg) {
    double	dou = std::atof(arg.c_str());
	float	flo = static_cast<float>(dou);

    if (dou >= 32 && dou <= 126)
			std::cout << "char: '" << static_cast<char>(dou) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	
	if (dou <= 2147483647 && dou >= -2147483648)
		std::cout << "int: " << static_cast<int>(dou) << std::endl;
	else
		std::cout << "int: impossible\n";
	if (flo == flo)
		std::cout << "float: " << std::fixed << std::setprecision(1) << flo << "f\n";
	else
		std::cout << "float: nanf\n";
	if (dou == dou)
		std::cout << "double: " << std::fixed << std::setprecision(1) << dou << std::endl;
	else
		std::cout << "double: nan\n";
}

void ScalarConverter::convertToString() {
	std::cout << "char: impossible\n"
	<< "int: impossible\n"
	<< "float: impossible\n"
	<< "double: impossible\n";
}