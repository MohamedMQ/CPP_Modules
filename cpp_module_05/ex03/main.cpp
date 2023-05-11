/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:43:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 14:14:55 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void func() {
    system("leaks Form");
}

int main(void) {
    std::cout << "\033[31mStart\033[0m\n";
    std::cout << "\033[33m-----------------PresidentialPardonForm-----------------\033[0m\n";
    AForm *newForm = NULL;
    try {
        Intern presidentIntern;
        Bureaucrat simo("Simo", 30);
        newForm = presidentIntern.makeForm("robotomy", "Prisonner");
        simo.signForm(*newForm);
        simo.executeForm(*newForm);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Intern::WrongFormName& e) {
        std::cerr << e.what() << std::endl;
    }
    delete newForm;
    newForm = NULL;
    std::cout << "\033[33m-----------------ShrubberyCreationForm-----------------\033[0m\n";
    try {
        Intern shrubbery;
        Bureaucrat hossam("Hossam", 14);
        newForm = shrubbery.makeForm("shrubbery creation", "Lavender");
        hossam.signForm(*newForm);
        hossam.executeForm(*newForm);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Intern::WrongFormName& e) {
        std::cerr << e.what() << std::endl;
    }
    delete newForm;
    newForm = NULL;
    std::cout << "\033[33m-----------------RobotomyRequestForm-----------------\033[0m\n";
    try {
        Intern robotomy;
        Bureaucrat youness("Youness", 120);
        newForm = robotomy.makeForm("robotomy request", "Alien");
        youness.signForm(*newForm);
        youness.executeForm(*newForm);
    } catch (AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Intern::WrongFormName& e) {
        std::cerr << e.what() << std::endl;
    }
    delete newForm;
    std::cout << "\033[31mEnd\033[0m\n";
    atexit(func);
    return 0;
}