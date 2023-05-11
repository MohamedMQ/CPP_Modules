/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:32:58 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:33:00 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main () {
    std::cout << "\033[31mStart\033[0m\n";
    try {
        Bureaucrat simo("Simo", 15);
    } catch(Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch(Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat rida("Rida", 151);
    } catch(Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch(Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat hossam("Hossam", 150);
    try {
        hossam.decrementGrade();
    } catch(Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch(Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat yassin("Yassin", 1);
    try {
        yassin.incrementGrade();
    } catch(Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch(Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[31mEnd\033[0m\n";
    return 0;
}