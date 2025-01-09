/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/16 16:04:27 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Clap1("MeanClap");

	int x = 0;
	
	while (x < 8)
	{
		Clap1.attack("Bob");
		Clap1.takeDamage(1);
		Clap1.beRepaired(1);
		std::cout << Clap1;
		x++;
	}
	ClapTrap Clap2 = Clap1;
	x = 0;
	while (x < 8)
	{
		Clap2.attack("Bob");
		Clap2.takeDamage(1);
		Clap2.beRepaired(1);
		std::cout << Clap2;
		x++;
	}
}
