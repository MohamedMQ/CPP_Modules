/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:41:52 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:41:54 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
    std::cout << "\033[31mStart\033[0m\n";
    try {
		Bureaucrat simo("Simo", 0);
        try {
            std::string form = "Acceptance Form";
            Form firstForm(form, 2, 4);
            simo.signForm(firstForm);
        } catch (Form::GradeTooHighException& e) {
            std::cerr << e.what() << std::endl;
        } catch (Form::GradeTooLowException& e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
	}
    std::cout << "\033[31mEnd\033[0m\n";
    return 0;
}