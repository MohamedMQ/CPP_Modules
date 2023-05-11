/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:40:47 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:40:49 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
		const std::string	_name;
		int _grade;

    public:
		Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &obj);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooLowException : std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

#endif