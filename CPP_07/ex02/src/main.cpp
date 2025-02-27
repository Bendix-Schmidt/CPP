/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:21:56 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/27 15:33:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define MAX_VAL 750

int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    // Fill the array and mirror with random values
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Verify initial filling by printing the first 5 elements
    std::cout << "First 5 elements of numbers array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // SCOPE: Test copy constructor
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		std::cout << "First 5 elements of test array before modifzing test: ";
		for (int i = 0; i < 5; i++) {
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;

        // Modify test array and check original
        for (int i = 0; i < 5; i++) {
            test[i] = -1; // Set to -1 to indicate a change
        }

        std::cout << "First 5 elements of numbers array after modifying test array: ";
        for (int i = 0; i < 5; i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
		std::cout << "First 5 elements of test array after modifying test array: ";
        for (int i = 0; i < 5; i++) {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;
    }

    // Test assignment operator
    Array<int> anotherArray = numbers;
    for (int i = 0; i < 5; i++) {
        anotherArray[i] = -2; // Set to -2 to indicate a change
    }

    std::cout << "First 5 elements of numbers array after modifying anotherArray: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Verify that mirror and numbers are still the same
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Test out-of-bounds access
    try {
        numbers[-2] = 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // Refill numbers with new random values
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    delete[] mirror;
    return 0;
}
