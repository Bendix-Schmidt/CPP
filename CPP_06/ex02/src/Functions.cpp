/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:39:33 by bschmidt          #+#    #+#             */
/*   Updated: 2025/03/04 18:46:25 by bschmidt         ###   ########.fr       */
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

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "& = class A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "& = class B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "& = class C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "class could not be identified" << std::endl;
			}
		}
	}
}