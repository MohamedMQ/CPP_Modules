/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:43:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:43:38 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) {
    *this = obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &obj) {
    (void)obj;
    return (*this);
}

const char *Intern::WrongFormName::what(void) const throw() {
	return ("Wrong form name :\n1) robotomy request.\n2) presidential pardon.\n3) shrubbery creation");
};

AForm* Intern::makeForm(std::string formName, std::string Formtarget) {
    AForm* newForm;
    int j = 0;

    std::string	formNameList[] = {
		"robotomy request",
		"presidential pardon", 
		"shrubbery creation",
	};
    for(; j < 3; j++) {
        if (formName == formNameList[j])
            break;
    }
    switch (j) {
		case 0:
    		newForm = new RobotomyRequestForm(Formtarget);
            break;
  		case 1:
            newForm = new PresidentialPardonForm(Formtarget);
            break;
 		case 2:
    		newForm = new ShrubberyCreationForm(Formtarget);
			break ;
		default:
    		throw Intern::WrongFormName();
	}
    std::cout << "Intern creates " << formNameList[j] << std::endl;
    return (newForm);
}