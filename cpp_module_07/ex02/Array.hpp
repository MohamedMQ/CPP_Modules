/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/27 11:06:50 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T           *_arr;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& obj);
        ~Array();
        Array& operator=(const Array& obj);
        T& operator[](unsigned int j);
        const T& operator[](unsigned int j) const;
        class IndexOutOfRange : public std::exception {
            private:
                const char *_msg;
            public:
                IndexOutOfRange();
                IndexOutOfRange(const char *msg);
                const char *what() const throw();
        };
        unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _size(0) {
    _arr = new T[0];
    std::cout << "Default constructor has been called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _size = n;
    _arr = new T[_size];
    std::cout << "Parameterized constructor has been called\n";
}

template <typename T>
Array<T>::Array(const Array<T>& arr) {
    unsigned int i;

    _size = arr._size;
    _arr = new T[_size];
    i = 0;
    while (i < _size) {
        _arr[i] = arr._arr[i];
        i++;
    }
    std::cout << "Copy constructor has been called\n";
}

template <typename T>
Array<T>::~Array() {
    delete[] _arr;
    std::cout << "Default destructor has been called\n";
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr) {
    unsigned int i;

    if (this != arr) {
        delete[] _arr;
        _arr = NULL;
        _size = arr._size;
        _arr = new T[_size];
        i = 0;
        while (i < _size) {
            _arr[i] = arr._arr[i];
            i++;
        }
    }
    std::cout << "Assignement operator has been called\n";
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int j) {
    if (j >= _size)
        throw IndexOutOfRange("Index is out of bounds");
    return _arr[j];
}

template <typename T>
const T& Array<T>::operator[](unsigned int j) const {
    if (j >= _size)
        throw IndexOutOfRange("Index is out of bounds");
    return _arr[j];
}

template <typename T>
Array<T>::IndexOutOfRange::IndexOutOfRange() : _msg("Index is out of bounds") {}

template <typename T>
Array<T>::IndexOutOfRange::IndexOutOfRange(const char *msg) : _msg(msg) {}

template <typename T>
const char *Array<T>::IndexOutOfRange::what() const throw() {
    return (_msg);
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif
