/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 12:26:42 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Scav1;
	Scav1.attack("Bobby");
	/* ClapTrap Clap1("MeanClap");
	ScavTrap Scav1("ReallyMeanClap");

	Clap1.attack("Bob");
	//Clap1.takeDamage(1);
	//Clap1.beRepaired(1);
	//std::cout << Clap1;
	Scav1.attack("Bobby");
	Scav1.guardGate();
	ScavTrap Scav2 = Scav1;
	Scav2.set_name("ReallyMeanClap2");
	Scav2.attack("Charly"); */
}
