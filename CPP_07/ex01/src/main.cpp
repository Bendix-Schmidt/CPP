/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:05:13 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 16:19:17 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Integer array before increment:" << std::endl;
    iter(intArray, intArrayLength, printArray<int>);
	iter(intArray, intArrayLength, incrementArray<int>);
    std::cout << "Integer array after increment:" << std::endl;
	iter(intArray, intArrayLength, printArray<int>);
}