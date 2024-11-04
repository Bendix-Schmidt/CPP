/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:20:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/29 14:29:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *heap_Zombie = newZombie("HeapZombie");

	heap_Zombie->announce();
	delete(heap_Zombie);

	heap_Zombie = newZombie("newHeapZombie");
	heap_Zombie->announce();
	delete(heap_Zombie);

	randomChump("StackZombie");
	randomChump("NewStackZombie");
}