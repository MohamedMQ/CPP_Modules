/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:05:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:07 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	{
		std::cout << "----------> Subject Test" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "----------> Character test" << std::endl;
		ICharacter* char1 = new Character("char1");
		(void)char1;
		std::cout << "--char1--OK" << std::endl;
		Character char2 = Character("char2");
		std::cout << "--char2--OK" << std::endl;
		Character char3 = Character(char2);
		std::cout << "--char3--OK" << std::endl;
		Character char4 = char2;
		std::cout << "--char4--OK" << std::endl;

		delete char1;
	}
	{
		std::cout << "----------> Character test2" << std::endl;
		Character char1 = Character("char1");
		Character char2 = Character("char2");
		std::cout << "--char2 equip--" << std::endl;
		char2.equip(new Ice());
		char2.equip(new Cure());
		char2.equip(new Ice());
		char2.equip(new Cure());
		char2.equip(new Cure());
		std::cout << "--char2 use--" << std::endl;
		char2.use(0, char1);
		char2.use(1, char1);
		char2.use(2, char1);
		char2.use(3, char1);
		char2.use(4, char1);
		char2.unequip(1);
		char2.unequip(3);
		std::cout << "--char2 unequip--" << std::endl;
		char2.use(1, char1);
		char2.use(3, char1);
		char2.equip(new Ice());
		char2.use(1, char1);
		char2.use(3, char1);
	}
	{
		std::cout << "----------> IMateriaSource TEST" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("truc");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(-1, *bob);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}
