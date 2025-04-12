/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:13:03 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 18:25:38 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <cstdlib>
#include <climits>

void check_args(int argc, char **argv)
{
	if (argc == 1)
		throw std::runtime_error("At least 1 number needed");

	bool is_sorted = true;
	std::set<long> seen_numbers;
	
	for (int i = 1; i < argc; i++)
	{
		char *arg = argv[i];
		if (arg[0] == '\0')
			throw std::runtime_error("Empty argument is not allowed");
			
		for (int j = 0; arg[j] != '\0'; j++)
		{
			if (!isdigit(arg[j]))
				throw std::runtime_error("All arguments must consist of only digits");
		}
		
		long num = std::atol(arg);
		if (num > INT_MAX)
			throw std::runtime_error("Numbers cant exceed Maxint");
		
		if (seen_numbers.find(num) != seen_numbers.end())
		throw std::runtime_error("Duplicate numbers are not allowed");
		seen_numbers.insert(num);
		
		if (i > 1)
		{
			int prev_num = std::atoi(argv[i - 1]);
			int curr_num = std::atoi(argv[i]);
			if (curr_num < prev_num)
				is_sorted = false;
		}
	}
	if (is_sorted)
		throw std::runtime_error("Sequence is sorted already");
}

void seqBeforeSort(int argc, char **argv)
{
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::seqAfterSort()
{
	std::cout << "After: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::is_sorted()
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it)
	{
		if (*it > *(it + 1))
		{
			std::cout << "Vector not sorted" << std::endl;
			return (false);
		}
	}

	for (std::deque<int>::iterator it = deque.begin(); it != deque.end() - 1; ++it)
	{
		if (*it > *(it + 1))
		{
			std::cout << "Deque not sorted" << std::endl;
			return (false);
		}
	}
	return (true);
}

int main(int argc, char **argv)
{
	try
	{
		check_args(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	PmergeMe pm(argc, argv);
	seqBeforeSort(argc, argv);
	pm.sort();
	pm.seqAfterSort();
	if (pm.is_sorted())
		std::cout << "\033[1;32mSequence sorted successfully\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mNot sorted properly\033[0m" << std::endl;
	std::cout 	<< "Time to process a range of " << argc - 1
				<< " elements using vectors: " << pm.getVecTime()
				<< " us" << std::endl;
	std::cout 	<< "Time to process a range of " << argc - 1
				<< " elements using deque: " << pm.getDequeTime() 
				<< " us" << std::endl;
	return (0);
}
