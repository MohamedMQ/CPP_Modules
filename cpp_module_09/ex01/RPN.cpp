/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:10 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:11 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &obj) {
    *this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
	if (this != &obj)
		this->_nums = obj._nums;
	return (*this);
}

void RPN::checkEquationRPN(std::string const &equation) {
	std::istringstream ssEquation(equation);
	std::string el, nums = "0123456789", operators = "+-*/";

	while (!ssEquation.eof()) {
		if (!(ssEquation >> el)) {
			std::cerr << "Error\n";
			exit(1);
		}
		if ((el.size() == 1
			&& (nums.find(el[0]) != std::string::npos
			|| operators.find(el[0]) != std::string::npos))
			|| (el.size() == 2
			&& (el[0] == '-' && nums.find(el[1]) != std::string::npos)))
			continue;
		else {
			std::cerr << "Error\n";
			exit(1);
		}
	}
}

void RPN::calcRPN(std::string const &ch) {
	float num1, num2, res;

	if (_nums.size() < 2) {
		std::cerr << "Error\n";
		exit(1);
	}
	num2 = _nums.top();
	_nums.pop();
	num1 = _nums.top();
	_nums.pop();
	if (ch == "+") {
		res = num1 + num2;
		_nums.push(res);
	} else if (ch == "-") {
		res = num1 - num2;
		_nums.push(res);
	} else if (ch == "*") {
		res = num1 * num2;
		_nums.push(res);
	} else if (ch == "/") {
		if (num2 == 0) {
			std::cerr << "Error\n";
			exit(1);
		}
		res = num1 / num2;
		_nums.push(res);
	}
}

void RPN::calcEquationRPN(std::string const &equation) {
	std::istringstream ssEquation(equation);
	std::string el, nums = "0123456789", operators = "+-*/";

	while (!ssEquation.eof()) {
		if (!(ssEquation >> el)) {
			std::cerr << "Error\n";
			exit(1);
		}
		if ((el.size() == 1
			&& (nums.find(el[0]) != std::string::npos))
			|| (el.size() == 2
			&& (el[0] == '-' && nums.find(el[1]) != std::string::npos)))
			_nums.push(std::atoi(el.c_str()));
		else
			calcRPN(el);
	}
	if (_nums.size() != 1) {
		std::cerr << "Error\n";
		exit(1);
	}
	if (!_nums.top()) {
		_nums.pop();
		_nums.push(0);
	}
}

void RPN::parseCalcRPN(std::string const &equation) {
	checkEquationRPN(equation);
	calcEquationRPN(equation);
	std::cout << _nums.top() << "\n";
}