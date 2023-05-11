/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("Character") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_trash_count = 0;
	this->_trash_size = 4;
	this->_trash = new AMateria *[this->_trash_size];
}

Character::Character(std::string const & name): _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_trash_count = 0;
	this->_trash_size = 4;
	this->_trash = new AMateria *[this->_trash_size];
}

Character::Character(Character const &src): _name(src._name) {
	int	i;

	i = 0;
	while (i < 4) {
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
		i++;
	}	
	this->_name = src._name;
	this->_trash_count = 0;
	this->_trash_size = 4;
	this->_trash = new AMateria *[this->_trash_size];
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	for (int i = 0; i < this->_trash_count; i++)
		if (this->_trash[i] != NULL)
			delete this->_trash[i];
	delete [] this->_trash;
}

void	Character::init_trash(void) {
	AMateria	**tmp;

	tmp = new AMateria *[this->_trash_size * 2];
	for (int i = 0; i < this->_trash_size; i++)
		tmp[i] = this->_trash[i];
	for (int i = this->_trash_size; i < this->_trash_size * 2; i++)
		tmp[i] = NULL;
	delete [] this->_trash;
	this->_trash = tmp;
	this->_trash_size *= 2;
}

Character &Character::operator=(Character const &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (rhs._inventory[i] != NULL)
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	this->_name = rhs._name;
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
		this->_trash_count++;
		if (this->_trash_count == this->_trash_size)
			this->init_trash();
		this->_trash[this->_trash_count - 1] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "No such item" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No such item" << std::endl;
}



