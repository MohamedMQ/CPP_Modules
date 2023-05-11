/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:02 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/11 13:05:32 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALER_HPP
# define SCALER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter {
    private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &old_obj);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &old_obj);
		static int checkIfIsInt(std::string arg);
		static int checkIfIsChar(std::string arg);
		static int checkIfIsFloat(std::string arg);
		static int checkIfIsDouble(std::string arg);
		static void convertIfInt(std::string arg);
		static void convertIfChar(std::string arg);
		static void convertIfFloat(std::string arg);
		static void convertIfDouble(std::string arg);
		static int convertFloDouPsLi(std::string arg, char c);
		static void printResultFlDo(std::string arg);
		static void convertToString();

    public:
		static void	convert(std::string string);
};

#endif  