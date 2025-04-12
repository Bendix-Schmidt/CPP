/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:12:57 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 18:07:55 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

int PmergeMe::jtNumber(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	int j_n_minus1 = 1;
	int j_n_minus2 = 0;
	int j_n = 0;
	
	for (int i = 2; i <= n; i++)
	{
		j_n = j_n_minus1 + 2 * j_n_minus2;
		j_n_minus2 = j_n_minus1;
		j_n_minus1 = j_n;
	}
	
	return (j_n);
}

std::vector<int> getJtInsertionOrder(int n)
{
	std::vector<int> result;
	if (n <= 0)
		return (result);
	
	//get necessry Jt-numbers
	std::vector<int> jacobsthalNumbers;
	jacobsthalNumbers.push_back(0);  // J(0) = 0
	jacobsthalNumbers.push_back(1);  // J(1) = 1
	
	int i = 2;
	while (jacobsthalNumbers.back() < n)
	{
		int next = jacobsthalNumbers[i-1] + 2 * jacobsthalNumbers[i-2];
		jacobsthalNumbers.push_back(next);
		i++;
	}
	
	std::vector<bool> used(n + 1, false); //initialize vector to hold boolean values (n + 1, set to false by default)
	
	//insert first element always
	result.push_back(1);
	used[1] = true;
	
	//insert rest based on jt sequnce
	for (size_t j = 3; j < jacobsthalNumbers.size(); j++)
	{
		//insert jt number
		int pos = jacobsthalNumbers[j];
		if (pos <= n && !used[pos])
		{
			result.push_back(pos);
			used[pos] = true;
		}
		
		//insert all elements between this and last jacobsthal number
		for (int k = pos - 1; k > jacobsthalNumbers[j-1]; k--)
		{
			if (k <= n && !used[k])
			{
				result.push_back(k);
				used[k] = true;
			}
		}
	}
	
	//insert rest of elemnts
	for (int j = 1; j <= n; j++)
	{
		if (!used[j])
		{
			result.push_back(j);
		}
	}
	return (result);
}

template <typename Container>
typename Container::iterator binarySearchPosition(Container& container, int value)
{
    return std::lower_bound(container.begin(), container.end(), value);
}

template <>
std::deque<int>::iterator binarySearchPosition(std::deque<int>& container, int value)
{
    size_t left = 0;
    size_t right = container.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (container[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return container.begin() + left;
}

void PmergeMe::sort()
{
	clock_t startVector = clock();
	mergeInsert(vec, getJtInsertionOrder);
	clock_t endVector = clock();
	vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeque = clock();
	mergeInsert(deque, getJtInsertionOrder);
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