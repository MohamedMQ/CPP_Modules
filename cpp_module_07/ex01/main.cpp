/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:26 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/26 11:18:17 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int len;
    int arr1[] = {10, 13, -81, 20, 16, 0};

    len = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "\033[31m==== BEGIN ====\033[0m" << std::endl;
    std::cout << " -------------------------------------\n";
    std::cout << "|\033[32m       TEST INTEGER ARRAY TYPE       \033[0m|\n";
    std::cout << " -------------------------------------\n";
    iter(arr1, len, evenOrOdd<int>);
    char arr2[] = {'A', 'c', 't', '%', 'V', 'p'};
    len = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << " -------------------------------------\n";
    std::cout << "|\033[32m         TEST CHAR ARRAY TYPE        \033[0m|\n";
    std::cout << " -------------------------------------\n";
    iter(arr2, len, toUpperOrLower<char>);
    std::cout << "\033[31m==== END ====\033[0m" << std::endl;
}