/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:13:10 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 18:24:11 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>

std::vector<int> getJtInsertionOrder(int n);

template <typename Container>
typename Container::iterator binarySearchPosition(Container& container, int value);

// Declare specialization for std::deque
template <>
std::deque<int>::iterator binarySearchPosition(std::deque<int>& container, int value);

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deque;
		double vectorTime;
		double dequeTime;
	
	public:
		//methods
		void sort();
		void seqAfterSort();
		bool is_sorted();

		//getters
		double getVecTime();
		double getDequeTime();

		//constructors && destructor
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
	private:
		int jtNumber(int n);

		// Template function definition must be in the header file
		template <typename Container, typename Callable>
		void mergeInsert(Container& container, Callable getJtInsertionOrder)
		{
			if (container.size() <= 1)
				return;

			// Build pairs
			std::vector<std::pair<int, int> > pairs;
			typename Container::iterator it = container.begin();
			int single = -1;

			while (it != container.end())
			{
				int first = *it++;
				if (it != container.end())
				{
					int second = *it++;
					if (first > second)
						pairs.push_back(std::make_pair(second, first));
					else
						pairs.push_back(std::make_pair(first, second));
				}
				else
				{
					single = first;
				}
			}

			// Sort container with bigger elements
			Container sorted;
			for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin();
				 it != pairs.end(); ++it)
			{
				sorted.push_back(it->second);
			}

			if (sorted.size() > 1)
				mergeInsert(sorted, getJtInsertionOrder);

			// Store the smaller elements in a vector for easier access
			std::vector<int> smallerElements;
			for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin();
				 it != pairs.end(); ++it)
			{
				smallerElements.push_back(it->first);
			}

			std::vector<int> insertionOrder = getJtInsertionOrder(smallerElements.size());

			// Insert the smaller elements according to the Jacobsthal sequence
			for (size_t i = 0; i < insertionOrder.size(); i++)
			{
				int index = insertionOrder[i] - 1; // -1 because indices start at 0
				if (index < static_cast<int>(smallerElements.size()))
				{
					int valueToInsert = smallerElements[index];

					// Use std::lower_bound for containers that support random access (like vector),
					// and manual binary search for others (like deque)
					typename Container::iterator pos;
					pos = binarySearchPosition(sorted, valueToInsert);

					sorted.insert(pos, valueToInsert);
				}
			}

			// Push single element
			if (single != -1)
			{
				typename Container::iterator pos;
				pos = binarySearchPosition(sorted, single);
				sorted.insert(pos, single);
			}

			container = sorted;
		}
};

#endif // PMERGEME_HPP
