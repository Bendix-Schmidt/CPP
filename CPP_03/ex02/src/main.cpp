/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 15:44:40 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap Clap1("MeanClap");

	int x = 0;
	
	while (x < 16)
	{
		Clap1.attack("Bob");
		Clap1.takeDamage(1);
		Clap1.beRepaired(1);
		std::cout << Clap1;
		x++;
	}
}
