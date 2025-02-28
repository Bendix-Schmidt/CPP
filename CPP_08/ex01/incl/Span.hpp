/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:08:36 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/28 18:03:39 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>
#include <algorithm>
#include <cmath>


class Span
{
	private:
		unsigned int		N;		//maxSize would be better but subject :/
		unsigned int		storedNums;
		std::vector<int>	storage;
		
	public:
		//methods
		void	addNumber(int num);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	fillStorage(std::vector<int>::iterator start, std::vector<int>::iterator end);
		
		//getters
		unsigned int	getN() const;
		unsigned int	getStoredNums() const;
		int				getIntatIndex(int index) const;
		std::vector<int>::iterator	getStorageStart();
		std::vector<int>::iterator	getStorageEnd();

		//exceptions
		class	LimitException: public std::exception
		{
			virtual const char *what() const throw();
		};

		class	StorageException: public std::exception
		{
			virtual const char *what() const throw();	
		};
		
		//Constructors and destructors
		Span();
		Span(unsigned int n);
		Span(const Span &original);
		Span &operator=(const Span &original);
		~Span();
};

std::ostream	&operator<<(std::ostream &os, Span const &span);

#endif // SPAN_HPP