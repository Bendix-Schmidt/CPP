/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:15:57 by bschmidt          #+#    #+#             */
/*   Updated: 2025/03/02 14:58:10 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		//methods
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();

		typedef typename std::stack<T>::container_type::const_iterator  const_iterator;
		const_iterator	begin() const;
		const_iterator	end() const;

		typedef typename std::stack<T>::container_type::reverse_iterator  reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

		//constructors & destructor
		MutantStack();
		MutantStack(const MutantStack &original);
		MutantStack &operator=(const MutantStack &original);
		~MutantStack();
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP