/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:38 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/19 18:51:35 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Clap1("MeanClap");

	Clap1.attack("Bob");
	Clap1.takeDamage(11);
	Clap1.beRepaired(1);
}