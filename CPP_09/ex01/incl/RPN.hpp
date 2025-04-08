/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:20:02 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/08 19:36:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

class RPN
{
	private:
		std::stack<int> stack;
		
		//private methods (helper functions)
		bool isValidOperator(const std::string &token) const;
		int performOperation(int a, int b, const std::string &op) const;

	public:
		//methods:
		int evaluate(const std::string &expression);

		//consructors & desructor
		RPN();
		RPN(const RPN &oth);
		//copy assignment operator
		RPN &operator=(const RPN &oth);
		~RPN();
};

#endif // RPN_HPP