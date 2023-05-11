/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:42:30 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:42:32 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main () {
    std::cout << "\033[31mStart\033[0m\n";
    std::cout << "\033[33m-----------------PresidentialPardonForm-----------------\033[0m\n";
    try {
        Bureaucrat simo("Simo", 30);
        PresidentialPardonForm prisonner("Prisonner");
        simo.signForm(prisonner);
        simo.executeForm(prisonner);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[33m-----------------ShrubberyCreationForm-----------------\033[0m\n";
    try {
        Bureaucrat hossam("Hossam", 14);
        ShrubberyCreationForm lavender("Lavender");
        hossam.signForm(lavender);
        hossam.executeForm(lavender);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[33m-----------------RobotomyRequestForm-----------------\033[0m\n";
    try {
        Bureaucrat youness("Youness", 120);
        RobotomyRequestForm alien("Alien");
        youness.signForm(alien);
        youness.executeForm(alien);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[31mEnd\033[0m\n";

    return 0;
}