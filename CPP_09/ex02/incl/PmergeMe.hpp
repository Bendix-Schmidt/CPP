/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:13:10 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/10 19:13:12 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deque;
		double _vectorTime;
		double _dequeTime;
	
	public:
		void sort();
		void displayBefore() const;
		void displayAfter() const;

		//constructors && destructor
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
	private:
		void sortVector();
		void sortDeque();
		void mergeInsertVector(std::vector<int>& vec);
		void mergeInsertDeque(std::deque<int>& dq);
		bool isPositiveNumber(const std::string& str) const;
		int jacobsthalNumber(int n) const;
		std::vector<int> generateJacobsthalInsertionOrder(int n) const;
};

#endif // PmergeMe_HPP