/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:35:59 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 12:00:29 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    // std::cout << " ----------------------------------------\n";
    // std::cout << "|                BEGINING                |\n";
    // std::cout << " ----------------------------------------\n\n";
    // std::cout << "===> Their Test <====\n";

    // Span sp = Span(5);

    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    // std::cout << "====> My Test <====\n";
    // std::cout << "+++++++++ Invalid number of values\n";
    Span sp1(20000);
    Span sp2(10);
    Span sp3(20);
    try {
        std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        sp1.addNumber(50);
        std::cout << "Shortest Span: " << sp1.longestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "+++++++++ Adding Test 1\n";
    try {
        sp3.addNumber(20);
    } catch (const Span::excededMaxNumber& e) {
        std::cerr << e.what() << '\n';
    }
    std::vector<int> cpy1;
    std::srand(time(0));
    for (int i = 0; i < 20002; i++) {
        cpy1.push_back(std::rand() % 200);
    }
    std::vector<int>::iterator first = cpy1.begin();
    std::vector<int>::iterator last = cpy1.end() - 19992;
    try {
        sp3.addNumbersAtOnce(last, first);
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "longest Span: " << sp3.longestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "+++++++++ Adding Test 2\n";
    std::vector<int> cpy2;
    for (int i = 0; i < 10; i++) {
        cpy2.push_back(std::rand() % 200);
    }
    std::vector<int>::iterator start = cpy2.begin();
    std::vector<int>::iterator end = cpy2.end();
    try {
        sp2.addNumbersAtOnce(start, end);
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "longest Span: " << sp2.longestSpan() << std::endl;
    } catch(const Span::notEnouphNumberLenght& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << " ----------------------------------------\n";
    std::cout << "|                 ENDING                 |\n";
    std::cout << " ----------------------------------------\n";
    return (0);
}