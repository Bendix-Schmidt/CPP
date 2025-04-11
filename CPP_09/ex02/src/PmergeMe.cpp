/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:12:57 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 16:54:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

// Helper function to calculate Jacobsthal numbers
int PmergeMe::jacobsthalNumber(int n) const
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	int j_n_minus_1 = 1;
	int j_n_minus_2 = 0;
	int j_n = 0;
	
	for (int i = 2; i <= n; i++)
	{
		j_n = j_n_minus_1 + 2 * j_n_minus_2;
		j_n_minus_2 = j_n_minus_1;
		j_n_minus_1 = j_n;
	}
	
	return j_n;
}

// Generates the Jacobsthal insertion order for n elements
std::vector<int> PmergeMe::generateJacobsthalInsertionOrder(int n) const
{
	std::vector<int> result;
	if (n <= 0) return result;
	
	// Berechne alle benötigten Jacobsthal-Zahlen
	std::vector<int> jacobsthalNumbers;
	jacobsthalNumbers.push_back(0);  // J(0) = 0
	jacobsthalNumbers.push_back(1);  // J(1) = 1
	
	int i = 2;
	while (jacobsthalNumbers.back() < n) {
		int next = jacobsthalNumbers[i-1] + 2 * jacobsthalNumbers[i-2];
		jacobsthalNumbers.push_back(next);
		i++;
	}
	
	// Erstelle die Einfügereihenfolge
	std::vector<bool> used(n + 1, false);
	
	// Füge zuerst 1 ein (immer der erste)
	result.push_back(1);
	used[1] = true;
	
	// Füge dann die restlichen Elemente gemäß der Jacobsthal-Reihenfolge ein
	for (size_t j = 3; j < jacobsthalNumbers.size(); j++) {
		// Füge die Jacobsthal-Position ein
		int pos = jacobsthalNumbers[j];
		if (pos <= n && !used[pos]) {
			result.push_back(pos);
			used[pos] = true;
		}
		
		// Füge alle Positionen zwischen der aktuellen und vorherigen Jacobsthal-Zahl ein
		for (int k = pos - 1; k > jacobsthalNumbers[j-1]; k--) {
			if (k <= n && !used[k]) {
				result.push_back(k);
				used[k] = true;
			}
		}
	}
	
	// Füge alle verbleibenden Positionen ein
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			result.push_back(j);
		}
	}
	return result;
}

void PmergeMe::mergeInsertVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	// build pairs
	std::vector<std::pair<int, int> > pairs;
	int single = -1;
	size_t i = 0;
	
	while (i < vec.size())
	{
		int first = vec[i++];
		if (i < vec.size())
		{
			int second = vec[i++];
			if (first > second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
		}
		else
			single = first;
	}

	// sort vector with bigger elements
	std::vector<int> sorted;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); 
		 it != pairs.end(); ++it)
	{
		sorted.push_back(it->second);
	}

	if (sorted.size() > 1)
		mergeInsertVector(sorted);

	// Store the smaller elements in a vector for easier access
	std::vector<int> smallerElements;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); 
		 it != pairs.end(); ++it)
	{
		smallerElements.push_back(it->first);
	}
	
	// Generate the Jacobsthal insertion order
	std::vector<int> insertionOrder = generateJacobsthalInsertionOrder(smallerElements.size());

	// Insert the smaller elements according to the Jacobsthal sequence
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		int index = insertionOrder[i] - 1; // -1 because indices start at 0
		if (index < static_cast<int>(smallerElements.size()))
		{
			int valueToInsert = smallerElements[index];
			
			// For vector we can use binary search
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), valueToInsert);
			sorted.insert(pos, valueToInsert);
		}
	}

	// push single element
	if (single != -1)
	{
		// Binary search for the single element
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
		sorted.insert(pos, single);
	}
	vec = sorted;
}

void PmergeMe::mergeInsertDeque(std::deque<int>& dq)
{
	if (dq.size() <= 1)
		return;

	// build pairs
	std::deque<std::pair<int, int> > pairs;
	int single = -1;
	std::deque<int>::iterator it = dq.begin();
	
	while (it != dq.end())
	{
		int first = *it++;
		if (it != dq.end())
		{
			int second = *it++;
			if (first > second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
		}
		else
			single = first;
	}

	// sort deque with bigger elements
	std::deque<int> sorted;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); 
		 it != pairs.end(); ++it)
	{
		sorted.push_back(it->second);
	}

	if (sorted.size() > 1)
		mergeInsertDeque(sorted);

	// Store the smaller elements in a vector for easier access
	std::vector<int> smallerElements;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); 
		 it != pairs.end(); ++it)
	{
		smallerElements.push_back(it->first);
	}
	
	// Generate the Jacobsthal insertion order
	std::vector<int> insertionOrder = generateJacobsthalInsertionOrder(smallerElements.size());
	
	// Insert the smaller elements according to the Jacobsthal sequence
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		int index = insertionOrder[i] - 1; // -1 because indices start at 0
		if (index < static_cast<int>(smallerElements.size()))
		{
			int valueToInsert = smallerElements[index];
			
			// For deque we can use binary search
			size_t left = 0;
			size_t right = sorted.size();
			
			while (left < right)
			{
				size_t mid = left + (right - left) / 2;
				if (sorted[mid] < valueToInsert)
					left = mid + 1;
				else
					right = mid;
			}
			
			sorted.insert(sorted.begin() + left, valueToInsert);
		}
	}

	// push single element
	if (single != -1)
	{
		// Binary search for the single element
		size_t left = 0;
		size_t right = sorted.size();
		
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (sorted[mid] < single)
				left = mid + 1;
			else
				right = mid;
		}
		
		sorted.insert(sorted.begin() + left, single);
	}

	dq = sorted;
}

void PmergeMe::sort()
{
	clock_t startVector = clock();
	mergeInsertVector(vec);
	clock_t endVector = clock();
	vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeque = clock();
	mergeInsertDeque(deque);
	clock_t endDeque = clock();
	dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
}



//getters
double	PmergeMe::getDequeTime()
{
	return (dequeTime);
}

double	PmergeMe::getVecTime()
{
	return (vectorTime);
}

//Constructors, copy assignment operator & Destructor
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	vec.reserve(argc - 1); //preallocate memory to stop my vector from being moved around a lot :)
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
		deque.push_back(atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe& oth) : vec(oth.vec), deque(oth.deque)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& oth)
{
	if (this != &oth)
	{
		vec = oth.vec;
		deque = oth.deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}