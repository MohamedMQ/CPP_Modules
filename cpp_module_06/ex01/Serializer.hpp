/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:30 by mmaqbour          #+#    #+#             */
/*   Updated: 2024/01/10 16:50:32 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &obj);
		~Serializer();
		Serializer &operator=(const Serializer &obj);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif