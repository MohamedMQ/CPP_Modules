/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:08:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:08:18 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "==========================" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "==========================" << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << "==========================" << std::endl << std::endl;

	const WrongAnimal* metal = new WrongAnimal();
	const WrongAnimal* ile = new WrongCat();
	std::cout << "==========================" << std::endl << std::endl;
	
	std::cout << ile->getType() << " " << std::endl;
	ile->makeSound();
	metal->makeSound();
	std::cout << "==========================" << std::endl << std::endl;

	delete metal;
	delete ile;
	std::cout << "==========================" << std::endl << std::endl;

	Cat chat1;
	Cat chat2(chat1);

	std::cout << "==========================" << std::endl << std::endl;
	chat1.makeSound();
	chat2.makeSound();
	std::cout << "==========================" << std::endl << std::endl;

	Dog doggyto1;
	Dog doggyto2(doggyto1);

	std::cout << "==========================" << std::endl << std::endl;
	doggyto1.makeSound();
	doggyto2.makeSound();
	std::cout << "==========================" << std::endl << std::endl;

	Animal *animal[10];
	std::cout << "==========================" << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	std::cout << "==========================" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)
		animal[i]->makeSound();
	std::cout << "==========================" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal[i];
	return (0);
}