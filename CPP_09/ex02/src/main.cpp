/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:43:40 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/09 17:12:35 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Global comparison counter
int comparisonCount = 0;
int DEBUG = 0;
int TEST = 1;

// Comparison function to count comparisons
bool compare(int a, int b) {
	comparisonCount++;
	return a < b;
}

// Function to calculate Jacobsthal numbers
std::vector<int> generateJacobsthalNumbers(int n) {
	std::vector<int> jacobsthal;
	int i = 0;
	while (true) {
		int value = (static_cast<int>(std::pow(2, i + 1)) + static_cast<int>(std::pow(-1, i))) / 3;
		if (value > n) break;
		jacobsthal.push_back(value);
		i++;
	}
	return jacobsthal;
}

// Recursive function to pair and sort elements
void recursivePairing(std::vector<int>& sequence, std::vector<std::pair<int, int> >& pairs) {
	size_t n = sequence.size();
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (compare(sequence[i + 1], sequence[i])) {
			pairs.push_back(std::make_pair(sequence[i + 1], sequence[i])); // Swap to maintain order
		} else {
			pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
		}
	}
	if (n % 2 == 1) {
		pairs.push_back(std::make_pair(sequence.back(), -1)); // Handle odd element
	}

	// Debug: Print the pairs
	if (DEBUG == 1)
	{
		std::cout << "Pairs after recursive pairing:" << std::endl;
		for (size_t i = 0; i < pairs.size(); ++i)
		{
			std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
		}
		std::cout << std::endl;
	}
}

void binaryInsert(std::vector<int>& main, const std::vector<int>& pend)
{
	std::vector<int> jacobsthal = generateJacobsthalNumbers(static_cast<int>(pend.size()));

	// Insert elements based on Jacobsthal numbers
	for (size_t i = 1; i < jacobsthal.size(); ++i) { // Start from 1 to avoid overlap
		for (int j = jacobsthal[i - 1]; j < jacobsthal[i]; ++j)
		{
			if (j < static_cast<int>(pend.size()))
			{ // Ensure index is within bounds
				std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), pend[j], compare);
				main.insert(it, pend[j]);

				// Debug: Print main after each insertion
				if (DEBUG == 1)
				{
					std::cout << "Main after inserting " << pend[j] << ": ";
					for (size_t k = 0; k < main.size(); ++k)
					{
						std::cout << main[k] << " ";
					}
					std::cout << std::endl;
				}
			}
		}
	}

	// Insert remaining elements in reverse order
	for (int i = jacobsthal.back(); i < static_cast<int>(pend.size()); ++i) {
		std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), pend[i], compare);
		main.insert(it, pend[i]);

		// Debug: Print main after each insertion
		if (DEBUG == 1)
		{
			std::cout << "Main after inserting " << pend[i] << ": ";
			for (size_t k = 0; k < main.size(); ++k)
			{
				std::cout << main[k] << " ";
			}
			std::cout << std::endl;
		}
	}
}

// Ford-Johnson merge-insert sort
void fordJohnsonSort(std::vector<int>& sequence) {
	if (sequence.size() <= 1) return;

	// Step 1: Pair and sort
	std::vector<std::pair<int, int> > pairs;
	recursivePairing(sequence, pairs);

	// Step 2: Create main and pend sequences
	std::vector<int> main, pend;
	main.push_back(pairs[0].first); // Start with the smallest element
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].second != -1) {
			main.push_back(pairs[i].second);
			pend.push_back(pairs[i].first);
		} else {
			pend.push_back(pairs[i].first); // Handle odd element
		}
	}

	// Debug: Print main and pend before insertion
	if (DEBUG == 1)
	{
		std::cout << "Main before insertion: ";
		for (size_t i = 0; i < main.size(); ++i)
		{
			std::cout << main[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << "Pend before insertion: ";
		for (size_t i = 0; i < pend.size(); ++i)
		{
			std::cout << pend[i] << " ";
		}
		std::cout << std::endl;
	}
	// Step 3: Binary insert pend elements into main
	binaryInsert(main, pend);

	// Debug: Print main after all insertions
	if (DEBUG == 1)
	{
		std::cout << "Main after all insertions: ";
		for (size_t i = 0; i < main.size(); ++i)
		{
			std::cout << main[i] << " ";
		}
		std::cout << std::endl;
	}
	// Copy back to the original sequence
	sequence = main;
}

// Utility function to display a sequence
void displaySequence(const std::string& label, const std::vector<int>& sequence)
{
	std::cout << label;
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

//testing
int calculateMaxComparisons(int n)
{
	int maxComparisons = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		maxComparisons += static_cast<int>(std::ceil(std::log(value) / std::log(2)));
	}
	return (maxComparisons);
}

// Main function
int main(int argc, char* argv[])
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error: Provide a sequence of positive integers.");

		// Parse input
		std::vector<int> sequence;
		for (int i = 1; i < argc; ++i)
		{
			int num = std::atoi(argv[i]);
			if (num <= 0) {
				throw std::invalid_argument("Error: Only positive integers are allowed.");
			}
			sequence.push_back(num);
		}

		// Display the unsorted sequence
		displaySequence("Before: ", sequence);

		// Sort the sequence and measure time
		clock_t start = std::clock();
		fordJohnsonSort(sequence);
		clock_t end = std::clock();

		// Display the sorted sequence
		displaySequence("After:  ", sequence);

		// Display the time taken and comparison count
		double timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Time in microseconds
		std::cout << "Time to process a range of " << sequence.size()
				  << " elements: " << timeTaken << " us" << std::endl;
		if (TEST == 1)
		{
			int n = argc - 1;
			int maxComp = calculateMaxComparisons(n);
			std::cout << "max Comparisons allowed: " << maxComp << std::endl;
			std::cout << "comparisons used: " << comparisonCount << std::endl;
			if (comparisonCount <= maxComp)
				std::cout << "\033[32mTest passed\033[0m" << std::endl;
			else
				std::cout << "\033[31mTest failed\033[0m" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
