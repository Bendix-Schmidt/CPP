/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:59 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/22 17:07:38 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main (void)
{
	{
		const Animal* meta = new Animal();
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();
		const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;

		std::cout << meta->get_type() << ": ";
		meta->makeSound();
		std::cout << cat->get_type() << ": ";
		cat->makeSound();
		std::cout << dog->get_type() << ": ";
		dog->makeSound();
		std::cout << wrongMeta->get_type() << ": ";
		wrongMeta->makeSound();
		std::cout << k->get_type() << ": ";
		k->makeSound();

		std::cout << std::endl;

		delete(meta);
		delete(wrongMeta);
		delete(cat);
		delete(dog);
		delete(k);
	}

	return (0);
}