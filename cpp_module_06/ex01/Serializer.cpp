/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:25 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/10 16:50:27 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &obj) {
	*this = obj;
}

Serializer::~Serializer() {}

Serializer & Serializer::operator=(const Serializer &obj) {
	(void)obj;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t ptrResult;
	ptrResult = reinterpret_cast<uintptr_t>(ptr);
    return (ptrResult);
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data *rawResult;
	rawResult = reinterpret_cast<Data*>(raw);
    return (rawResult);
}