/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:19:16 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 14:45:58 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << " after increment" << std::endl;

		b1.incrementGrade();  // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << b2 << " after decrement" << std::endl;

		b2.decrementGrade();  // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Charlie", 0);  // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("David", 151);  // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}