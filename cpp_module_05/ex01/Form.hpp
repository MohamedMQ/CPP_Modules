/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:41:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:41:47 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
		Form();
      	Form(std::string &name, int gradeToSign, int gradeToExecute);
	    Form(const Form &obj);
	    ~Form();
	    Form &operator=(const Form &obj);
      	std::string getName() const;
      	int getGradeSign() const;
      	int getGradeExecute() const;
		bool isSigned() const;
   		void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooLowException : std::exception {
			public:
				const char *what() const throw ();
		};
		class GradeTooHighException : std::exception {
			public:
				const char *what() const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif