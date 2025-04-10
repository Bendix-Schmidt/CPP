/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:13:03 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/10 19:13:04 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/PmergeMe.hpp"
#include <cstdlib>
#include <climits>

void check_args(int argc, char **argv)
{
	if (argc == 1)
		throw "At least 1 number needed";
	bool is_sorted = true;
	for (int i = 1; i < argc; i++)
	{
		char *arg = argv[i];
		for (int j = 0; j != '\0'; j++)
		{
			if (!isdigit(arg[j]))
				throw "All arguments must consist of only digits";
		}
		long num = std::atol(arg);
		if (num > INT_MAX)
			throw "Numbers cant exceed Maxint";
		if (i > 1)
		{
			int prev_num = std::atoi(argv[i - 1]);
			int curr_num = std::atoi(argv[i]);
			if (curr_num < prev_num)
				is_sorted = false;
		}
	}
	if (is_sorted)
		throw "Sequence is sorted already";
}

int main(int argc, char **argv)
{
	try
	{
		check_args(argc, argv);
	}
	catch (const char *error)
	{
		std::cerr << "Error: " << error << std::endl;
		return (1);
	}
	PmergeMe pm(argc, argv);
	pm.displayBefore();
	pm.sort();
	pm.displayAfter();
	
	return 0;
}
