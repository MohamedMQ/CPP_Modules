/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:17 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/10 16:51:19 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

Base *generate(void) {
    int random;

    std::srand(std::time(NULL));
    random = std::rand() % 3;
    switch (random) {
        case 0:
            std::cout << "Creating an A pointer\n";
            return (new A());
        case 1:
            std::cout << "Creating an B pointer\n";
            return (new B());
        case 2:
            std::cout << "Creating an C pointer\n";
            return (new C());
        default:
            std::cout << "Failed to create pointer\n";
            break;
    }
    return (NULL);
}

void identify(Base* p) {
    A* ptrA = dynamic_cast<A*>(p);
    B* ptrB = dynamic_cast<B*>(p);
    C* ptrC = dynamic_cast<C*>(p);
    !ptrA
    ? ptrA->getToKnowMe()
    : !ptrB
    ? ptrB->getToKnowMe()
    : !ptrC
    ? ptrC->getToKnowMe()
    : (void)(std::cerr << "Error\nNeither A, B, or C\n");
}

void identify(Base& p) {
    try {
        A& refA = dynamic_cast<A&>(p);
        refA.getToKnowMe();
    } catch(std::exception &e) {
        try {
            B& refB = dynamic_cast<B&>(p);
            refB.getToKnowMe();
        } catch(std::exception &e) {
            try {
                C& refC = dynamic_cast<C&>(p);
                refC.getToKnowMe();
            } catch(std::exception &e) {
                std::cerr << "Error\nNeither A, B, or C\n";
            }
        }
    }  
}