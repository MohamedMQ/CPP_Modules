/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:19 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/27 11:15:04 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    size_t len = 3;
    Array<int> arrOfInt(len);

    arrOfInt[0] = 6;
    arrOfInt[1] = 0;
    arrOfInt[2] = -20;
    std::cout << "Array int before : ";
    for (size_t i = 0; i < len; i++)
        std::cout << arrOfInt[i] << " ";
    std::cout << "\nThe size of the int array is : " << arrOfInt.size() << std::endl;
    for (size_t i = 0; i < len; i++)
        arrOfInt[i] = arrOfInt[i] * 10;
    std::cout << "Array int after : ";
    for (size_t i = 0; i < len; i++)
        std::cout << arrOfInt[i] << " ";
    try {
        std::cout << "\nThe first element of the arrOfInt is : " << arrOfInt[0] << std::endl;
        std::cout << "Index \">= len\" or \"< 0\" gives this result : " << arrOfInt[2] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}