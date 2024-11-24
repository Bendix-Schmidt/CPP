/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:58:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 20:22:17 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//member function
void	Cat::makeSound() const
{
	std::cout << "Meoooww" << std::endl;
}

//getter
std::string	Cat::get_idea(int index) const
{
	return (brain->get_idea(index));
}
//setter
void	Cat::set_idea(int index, std::string idea)
{
	brain->set_idea(index, idea);
}

void	Cat::set_ideas(std::string idea)
{
	brain->set_ideas(idea);
}

//printer
void	Cat::print_first_idea(std::ostream &stream) const
{
	brain->print_first_idea(stream);
}
void	Cat::print_all_ideas(std::ostream &stream) const
{
	brain->print_all_ideas(stream);
}
void	Cat::print_specific_idea(std::ostream &stream, int index) const
{
	brain->print_specific_idea(stream, index);
}

/*----------------------------------------------------------*/
//constructor
Cat::Cat() : Animal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "A Cat was born." << std::endl;
}

//copy constructor
Cat::Cat(const Cat &original) : Animal(original), brain(new Brain(*original.brain))
{
	this->type = original.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

//copy assignment operator
Cat&	Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
		*brain = *original.brain;
		this->type = original.type;
	}
	std::cout << "Cat copy assignment constructor called" << std::endl;
	return (*this);
}

//destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "A Cat died." << std::endl;
}

//<< operator
std::ostream	&operator<<(std::ostream &stream, Cat const &cat)
{
	stream << cat.get_type() << std::endl;
	return (stream);
}
