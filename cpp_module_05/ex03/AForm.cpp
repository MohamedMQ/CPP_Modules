/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:43:15 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 10:53:25 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("random"), _signed(0), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string &input_name, const int gradeSign, const int gradeExecute) : _name(input_name), _gradeToSign(gradeSign), _gradeToExecute(gradeExecute) {
     if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _signed(obj.isSigned()), _gradeToSign(obj.getGradeSign()), _gradeToExecute(obj.getGradeExecute()) {
    *this = obj;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm &obj) {
    (void)obj;
    return (*this);
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::isSigned() const {
	return this->_signed;
}

int AForm::getGradeSign() const {
    return (this->_gradeToSign);
}

int AForm::getGradeExecute() const {
    return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        this->_signed = 0;
        throw AForm::GradeTooLowException();
    } else
        this->_signed = 1;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (_signed == 0)
		throw AForm::IsNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    else
        this->runTheExecution(executor);
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
};

const char *AForm::IsNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& o, const AForm& form) {
	o << "The name: " << form.getName() << " has a grade to sign " << form.getGradeSign() << ", grade to execute " << form.getGradeExecute() << " and status of signed " << form.isSigned();
	return o;
}