/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:20 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/26 11:02:02 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename T1>
void iter(T *arr, int length, void (*func)(T1 &)) {
    int i = 0;

    while (i < length) {
        func(*(arr + i));
        i++;
    }
}

template <typename T>
void    evenOrOdd(T &value) {
    if (value % 2)
        std::cout << "Number " << value << " is odd number\n";
    else
        std::cout << "Number " << value << " is even number\n";
}

template <typename T>
void    toUpperOrLower(T &value) {
    if (std::isupper(value))
        std::cout << "Actual char " << value << " ==> lowercase " << static_cast<char>(std::tolower(value)) << std::endl;
    else if (std::islower(value))
        std::cout << "Actual char " << value << " ==> uppercase " << static_cast<char>(std::toupper(value)) << std::endl;
    else
        std::cout << "Actual char " << value << " ==> no upper or lower case\n";
}

#endif
