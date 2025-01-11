/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:59 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 15:10:13 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"

int	main (void)
{
	{
		const Animal* animal = new Animal();
		const WrongAnimal* wronganimal = new WrongAnimal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();
		const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;

		std::cout << animal->get_type() << ": ";
		animal->makeSound();
		std::cout << cat->get_type() << ": ";
		cat->makeSound();
		std::cout << dog->get_type() << ": ";
		dog->makeSound();
		std::cout << wronganimal->get_type() << ": ";
		wronganimal->makeSound();
		std::cout << k->get_type() << ": ";
		k->makeSound();

		std::cout << std::endl;

		delete(animal);
		delete(wronganimal);
		delete(cat);
		delete(dog);
		delete(k);
	}

	return (0);
}