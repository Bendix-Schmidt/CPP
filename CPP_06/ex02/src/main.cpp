/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:38:23 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 13:44:41 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main()
{
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
	return (0);
}

