/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:39:33 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:22 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate()
{
	srand(static_cast<unsigned int>(time(0)));
	int	random = rand() % 3;
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "* = class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "* = class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "* = class C" << std::endl;
	else
		std::cout << "class could not be identified" << std::endl;	
}

void	identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "& = class A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "& = class B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "& = Class C" << std::endl;
	else
		std::cout << "class could not be identified" << std::endl;
}