/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:11:57 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/12 14:12:01 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class Phonebook {
	
	public:
		Phonebook(void);
		~Phonebook(void);
		int 	search_contact(int index);
		void	print_one_contact(int index);
		int 	add_contact(int index);
		void	print_contact(int index);
		void	print_elem(std::string elem);

	private:
		Contact contacts[8];
};
