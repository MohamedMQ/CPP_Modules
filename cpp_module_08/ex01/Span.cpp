/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:41:56 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/06 11:34:09 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) {
	_N = N;
}

Span::Span(const Span &cpy) {
	*this = cpy;
}

Span::~Span() {}

Span& Span::operator=(const Span &cpy) {
	if (this != &cpy) {
		this->_N = cpy._N;
		this->_nums = cpy._nums;
	}
    return (*this);
}

void Span::addNumber(int num) {
	if (_nums.size() == _N)
		throw Span::excededMaxNumber();
	_nums.push_back(num);
}

unsigned long Span::shortestSpan() {
	unsigned long res;
	std::vector<int> cpy;
	unsigned long currentSpan;

	if (_nums.size() >= 2) {
		cpy = _nums;
		res = INT_MAX;
		std::sort(cpy.begin(), cpy.end());
		for (std::vector<int>::iterator iter = cpy.begin() + 1; iter < cpy.end(); iter++) {
			currentSpan = std::abs(*iter - *(iter - 1));
			if (currentSpan < res)
				res = currentSpan;
		}
	} else
		throw Span::notEnouphNumberLenght();
	return (res);
}

unsigned long Span::longestSpan() {
	unsigned long res;

	if (_nums.size() >= 2) {
		unsigned long shortestSpan = *std::min_element(_nums.begin(), _nums.end());
		unsigned long longestSpan = *std::max_element(_nums.begin(), _nums.end());
		res = longestSpan - shortestSpan;
	} else
		throw Span::notEnouphNumberLenght();
	return (res);
}

const char *Span::excededMaxNumber::what() const throw() {
	return ("Maximum number has been reached in the Vector");
}

const char *Span::notEnouphNumberLenght::what() const throw() {
	return ("Not enough number of values in the vector");
}

void Span::addNumbersAtOnce(std::vector<int>::iterator& start, std::vector<int>::iterator& end) {
	unsigned long numValues;

	numValues = std::distance(start, end);
	if (numValues < 0)
		throw std::out_of_range("Invalid range exception");
	if (_nums.size() == _N)
		throw Span::excededMaxNumber();
	if (numValues + _nums.size() > _N)
		throw std::out_of_range("Big range exception");
	_nums.insert(this->_nums.end(), start, end);
}