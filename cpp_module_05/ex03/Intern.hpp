/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:43:44 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:43:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &obj);
		~Intern();
		Intern &operator=(const Intern &obj);
		AForm *makeForm(std::string formName, std::string formtarget);
		class WrongFormName : std::exception {
			public:
				const char *what() const throw ();
		};
};

#endif