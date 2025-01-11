/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:59:10 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 15:30:33 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

//member function
void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

//getter
std::string	Dog::get_idea(int index) const
{
	return (brain->get_idea(index));
}
//setter
void	Dog::set_idea(int index, std::string idea)
{
	brain->set_idea(index, idea);
}

void	Dog::set_ideas(std::string idea)
{
	brain->set_ideas(idea);
}

//printer
void	Dog::print_first_idea(std::ostream &stream) const
{
	brain->print_first_idea(stream);
}
void	Dog::print_all_ideas(std::ostream &stream) const
{
	brain->print_all_ideas(stream);
}
void	Dog::print_specific_idea(std::ostream &stream, int index) const
{
	brain->print_specific_idea(stream, index);
}

/*----------------------------------------------------------*/
//constructor
Dog::Dog() : Animal(), brain (new Brain())
{
	this->type = "Dog";
	std::cout << "A Dog was born." << std::endl;
}

//copy constructor
//copy constructor
Dog::Dog(const Dog &original) : Animal(original), brain(new Brain(*original.brain))
{
	this->type = original.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

//copy assignment operator
Dog&	Dog::operator=(const Dog &original)
{
	if (this != &original)
	{
		*brain = *original.brain;
		this->type = original.type;
	}
	std::cout << "Dog copy assignment constructor called" << std::endl;
	return (*this);
}

//destructor
Dog::~Dog()
{
	delete brain;
	std::cout << "A Dog died." << std::endl;
}

//<< operator
std::ostream	&operator<<(std::ostream &stream, Dog const &Dog)
{
	stream << Dog.get_type() << std::endl;
	return (stream);
}
