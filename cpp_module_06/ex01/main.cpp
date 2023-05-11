/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:13 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/11 11:15:53 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data	*info = new Data;
	Data	*ptr = NULL;

	info->name = "mohamed";
	info->surname = "maqbour";
	info->username = "mmaqbour";
   	ptr = info;
    std::cout << "\033[1;31m____________Start____________\033[0m\n"
    << "variable Address -info-: " << &info << std::endl
	<< "Pointer value is: " << ptr << std::endl
    << "\033[33m------ After the serialization ------\033[0m\n";
    uintptr_t	ptrResult = Serializer::serialize(ptr);
	std::cout << "ptrResult is: " << ptrResult << std::endl
    << "\033[33m------ After the deserialization ------\033[0m\n";
    Data	*rawResult = Serializer::deserialize(ptrResult);
	std::cout << "rawResult is: " << rawResult << std::endl
	<< "variable Address -info-: " << &info << std::endl
    << "\033[33m------ checking infos ------\033[0m\n"
	<< "\033[32m==== Infos variables ====\033[0m\n"
	<< "Variable -name- of info: " << info->name << std::endl
	<< "Variable -surname- of info: " << info->surname << std::endl
	<< "Variable -username- of info: " << info->username << std::endl
	<< "The struct function member -displayInfo- of info: " << std::endl;
	info->displayInfo();
	std::cout << "\033[32m==== rawResult variables ====\033[0m\n"
	<< "Variable -name- of rawResult: " << rawResult->name << std::endl
	<< "Variable -surname- of rawResult: " << rawResult->surname << std::endl
	<< "Variable -username- of rawResult: " << rawResult->username << std::endl
	<< "The struct function member -displayInfo- of rawResult: " << std::endl;
	rawResult->displayInfo();
	std::cout << "\033[1;31m____________Finish____________\033[0m\n";
	delete info;
	return 0;
}