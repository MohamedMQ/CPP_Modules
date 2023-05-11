/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:30:18 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 11:58:28 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
    std::cout << " ----------------------------------------\n";
    std::cout << "|                BEGINING                |\n";
    std::cout << " ----------------------------------------\n\n";
    try {
        int numToSearch;
        char charToSearch;
        int arrInt[] = {89, 87, 11, 20, 155, 69};
        std::vector<int> nums(arrInt, (arrInt + sizeof(arrInt) / sizeof(int)));
		std::cout << "Numbers in the vector nums are : ";
		for (std::vector<int>::iterator start = nums.begin(); start < nums.end(); start++)
			std::cout << *(start) << " ";
        std::cout << std::endl;
        numToSearch = 155;
        std::cout << "number " << easyfind(nums, numToSearch) << " is found\n";
        char arrChar[] = {'A', 'B', 'C', 'D', 'E'};
        std::list<char> alphabet(arrChar, (arrChar + sizeof(arrChar) / sizeof(char)));
        alphabet.push_back('F');
        alphabet.push_back('G');
        charToSearch = 'F';
        std::cout << "Alphabet " << easyfind(alphabet, charToSearch) << " is found\n";
        nums.erase(nums.begin() + 4);
        std::cout << "Numbers in the updated vector nums are : ";
		for (std::vector<int>::iterator start = nums.begin(); start < nums.end(); start++)
			std::cout << *(start) << " ";
        std::cout << std::endl;
        numToSearch = 155;
        std::cout << "number " << easyfind(nums, numToSearch) << " is found\n";

    } catch (const notFoundException& err) {
        std::cerr << err.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << " ----------------------------------------\n";
    std::cout << "|                 ENDING                 |\n";
    std::cout << " ----------------------------------------\n";
    return 0;
}