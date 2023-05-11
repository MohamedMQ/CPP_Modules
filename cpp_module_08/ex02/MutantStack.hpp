/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:01:09 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/02/05 12:01:23 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTACK_HPP
# define MSTACK_HPP

# include <algorithm>
# include <iostream>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverseIterator;
		typedef typename std::stack<T>::container_type::const_iterator constIterator;
    	typedef typename std::stack<T>::container_type::const_reverse_iterator constReverseIterator;

		MutantStack();
		MutantStack(const MutantStack &cpy);
		~MutantStack();
    	MutantStack &operator=(const MutantStack &cpy);
		iterator begin();
		iterator end();
		reverseIterator rbegin();
		reverseIterator rend();
		constIterator cbegin();
		constIterator cend();
		constReverseIterator crbegin();
		constReverseIterator crend();
};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cpy) {
	*this = cpy;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &cpy) {
	if (this != &cpy)
		this->c = cpy.c;
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverseIterator MutantStack<T>::rbegin() {
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverseIterator MutantStack<T>::rend() {
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::constIterator MutantStack<T>::cbegin() {
	return (this->c.cbegin());
}

template<typename T>
typename MutantStack<T>::constIterator MutantStack<T>::cend() {
	return (this->c.cend());
}

template<typename T>
typename MutantStack<T>::constReverseIterator MutantStack<T>::crbegin() {
	return (this->c.crbegin());
}

template<typename T>
typename MutantStack<T>::constReverseIterator MutantStack<T>::crend() {
	return (this->c.crend());
}

#endif