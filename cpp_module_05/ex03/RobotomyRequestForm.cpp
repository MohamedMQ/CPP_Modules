/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:44:08 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/02 09:44:13 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("RobotomyRequestFormDefault") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target) {
    *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    (void) obj;
    return (*this);
}

void RobotomyRequestForm::runTheExecution(Bureaucrat const &executor) const {
    std::srand(std::time(NULL));

    (void)executor;
    if(std::rand() % 2)
        std::cout << this->_target << " has been robotomize successfully." << std::endl;
    else
        std::cout << "Robotomizing of " << this->_target << " has failed" << std::endl;
}
