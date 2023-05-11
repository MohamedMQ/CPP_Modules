/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:05:58 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:59 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string 	_name;
		AMateria		*_inventory[4];
		AMateria		**_trash;
		int				_trash_size;
		int				_trash_count;
		void			init_trash(void);
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const &src);
		virtual ~Character(void);
		Character &operator=(Character const &rhs);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif