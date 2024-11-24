/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:56:22 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 20:41:18 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//member functions:
//getter
std::string	Brain::get_idea(int index) const
{
	if (ideas[index].empty())
		return ("There is no idea at the requested index.");
	else
		return (this->ideas[index]);
}

//setter
void	Brain::set_ideas(std::string idea)
{
	for (int i = 0; i<100; i++)
	{
		ideas[i] = idea;
	}
}

void	Brain::set_idea(int i, std::string idea)
{
	this->ideas[i] = idea;
}

//printers
void	Brain::print_first_idea(std::ostream &stream) const
{
	if (ideas[0].empty())
		stream << "Idea[0] does not exist." << std::endl;
	else
		stream << ideas[0] << std::endl;
}

void	Brain::print_specific_idea(std::ostream &stream, int index) const
{
	if (index < 0 || index >= 100)
	{
		stream << "Index out of Idea-range." << std::endl;
		return ;
	}
	if (ideas[index].empty())
		stream << "Idea[" << index << "] does not exist." << std::endl;
	else
		stream << ideas[index] << std::endl;	
}

void	Brain::print_all_ideas(std::ostream &stream) const
{
	int i = 0;
	
	while (i < 100)
	{
		if (!ideas[i].empty())
			print_specific_idea(stream, i);
		i++;
	}
}

/*-----------------------------------------------------------------------*/
//standard constructor
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

//copy constructor
Brain::Brain(const Brain &original)
{
	std::cout << "Brain copied." << std::endl;
	*this = original;
}

//copy assigenment operator
Brain	&Brain::operator=(const Brain &original)
{
    if (this != &original)
	{
        for (int i = 0; i < 100; ++i)
		{
            this->ideas[i] = original.ideas[i];
    	}
	}
	return *this;
}

//standard destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
