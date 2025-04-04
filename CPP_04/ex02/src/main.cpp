/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:59 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 18:10:37 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Brain.hpp"
#include <iostream>

int main(void)
{
	//not possible to create object of abstract class
	//Animal	ananimal;
	
	//create dogs and cats
	Animal	*animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Cat();
	for (int i = 2; i < 4; i++)
		animals[i] = new Dog();
	std::cout << "\n\n" << std::endl;
	//access one dog
	Dog* dog = dynamic_cast<Dog*>(animals[2]);
	dog->makeSound();
	std::cout << dog->get_idea(0) << std::endl;
	dog->set_idea(0, "I think I am a dog");
	std::cout << dog->get_idea(0) << std::endl;
	Dog* dog2 = dynamic_cast<Dog*>(animals[3]);
	std::cout << dog2->get_idea(0) << std::endl;
	dog2 = dog;
	std::cout << dog2->get_idea(0) << std::endl;
	std::cout << "\n\n" << std::endl;
	//dog2->print_first_idea(std::cout);
	for (int i = 0; i < 4; i++)
	delete (animals[i]);
	return (0);
}