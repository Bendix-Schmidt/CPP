/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:00:24 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/29 18:01:36 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		n;
	Zombie	*horde;

	n = 10;
	horde = zombieHorde(n, "HordeZombie");	
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
}
