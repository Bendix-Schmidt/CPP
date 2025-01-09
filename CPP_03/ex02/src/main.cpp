/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/16 16:38:05 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap Clap1("MeanClap");
	ScavTrap Scav1("ReallyMeanClap");
	FragTrap Frag1("EvenMeanerClap");

	Clap1.attack("Bob");
	//Clap1.takeDamage(1);
	//Clap1.beRepaired(1);
	//std::cout << Clap1;
	Scav1.attack("Bobby");
	ScavTrap Scav2 = Scav1;
	Scav2.attack("Charly");
	Frag1.attack("Someone");
	FragTrap Frag2 = Frag1;
	Frag2.set_name("EvenMeanerClap2");
	Frag2.highFivesGuys();
}
