/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:41:31 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 13:36:33 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("random"), _signed(0), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form(std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &obj) : _name(obj.getName()), _signed(obj.isSigned()), _gradeToSign(obj.getGradeSign()), _gradeToExecute(obj.getGradeExecute()) {
    *this = obj;
}

Form::~Form() {}

Form& Form::operator=(const Form &obj) {
    (void)obj;
    return (*this);
}

std::string Form::getName() const {
    return (this->_name);
}

bool Form::isSigned() const {
	return this->_signed;
}

int Form::getGradeSign() const {
    return (this->_gradeToSign);
}

int Form::getGradeExecute() const {
    return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        this->_signed = 0;
        throw Form::GradeTooLowException();
    } else
        this->_signed = 1;
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
};

std::ostream& operator<<(std::ostream& o, const Form& form) {
	o << "The form : " << form.getName() << " has a grade to sign " << form.getGradeSign() << ", grade to execute " << form.getGradeExecute() << " and status of signed " << form.isSigned();
	return o;
}