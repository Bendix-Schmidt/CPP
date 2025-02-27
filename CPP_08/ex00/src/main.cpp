/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:13 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/27 16:45:07 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int arr[] = 		{1, 3, 5, 7, 9};
	std::vector<int>	vec(arr, arr+sizeof(arr) / sizeof(arr[0]));
	std::vector<int>::iterator	iterator;

	for (size_t i = 0; i <= 10; i++)
	{
		try
		{
			iterator = easyfind(vec, i);
			std::cout << "The value " << i << "was found at index " << *iterator << "in the container" << std::endl; 
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}