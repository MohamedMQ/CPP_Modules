/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:43:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:43:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("ShrubberyCreationFormDefault") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target) {
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    (void) obj;
    return (*this);
}

const char	*ShrubberyCreationForm::FileIsNotOpenException::what() const throw() {
	return ("File did not opened");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::runTheExecution(Bureaucrat const &executor) const {
    std::ofstream	ofs((this->_target + "_shrubbery").c_str());

    (void)executor;
	if (!ofs.is_open())
        throw ShrubberyCreationForm::FileIsNotOpenException();
    std::string shrubbery =	"\
            ^\n\
	        |\n\
	 	   (|)\n\
		  (/|\\)\n\
		 (//|\\\\)\n\
		(///|\\\\\\)\n\
	   (////|\\\\\\\\)\n\
	  (/////|\\\\\\\\\\)\n\
	 (//////|\\\\\\\\\\\\)\n\
	(///////|\\\\\\\\\\\\\\)\n\
   (////////|\\\\\\\\\\\\\\\\)\n\
     	   |||\n\
     	   |||\n\
     	   |||\n\
     	  /|||\\\n\
     	 //|||\\\\\n";
    ofs << shrubbery;
    ofs.close();
}