/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:54:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/29 17:59:40 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	int	i;

	i = 0;
	while(i < N)
	{
		horde[i].set_index(i);
		horde[i].set_name(name);
		i++;
	}
	return (horde);
}