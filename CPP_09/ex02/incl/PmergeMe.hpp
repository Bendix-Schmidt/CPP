/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:13:10 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 16:58:26 by bschmidt         ###   ########.fr       */
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
		void mergeInsertVector(std::vector<int>& vec);
		void mergeInsertDeque(std::deque<int>& dq);
		int jtNumber(int n);
		std::vector<int> getJtInsertionOrder(int n);
};

#endif // PmergeMe_HPP