/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:42:13 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 14:13:14 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
		AForm();
      	AForm(const std::string &name, const int gradeSign, const int gradeExecute);
	    AForm(const AForm &obj);
	    virtual ~AForm();
	    AForm &operator=(const AForm &obj);
      	std::string getName() const;
      	int getGradeSign() const;
      	int getGradeExecute() const;
		bool isSigned() const;
   		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void	runTheExecution(Bureaucrat const & executor) const = 0;
		class GradeTooLowException : std::exception {
			public:
				const char *what() const throw ();
		};
		class GradeTooHighException : std::exception {
			public:
				const char *what() const throw ();
		};
		class IsNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const AForm& AForm);

#endif