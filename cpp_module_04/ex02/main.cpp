/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:45 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// const Animal* meta = new Animal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();

	std::cout << "==========================" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	//meta->makeSound();
	std::cout << "==========================" << std::endl;

	//delete meta;
	delete j;
	delete i;
	std::cout << "==========================" << std::endl << std::endl;

	//const WrongAnimal* metal = new WrongAnimal();
	const WrongCat* ile = new WrongCat();
	std::cout << "==========================" << std::endl << std::endl;
	
	std::cout << ile->getType() << " " << std::endl;
	ile->makeSound(); //will not output the cat sound!
	//metal->makeSound();
	std::cout << "==========================" << std::endl << std::endl;

	//delete metal;
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

	return (0);
}