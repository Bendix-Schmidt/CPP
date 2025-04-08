/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:15:04 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/08 17:42:50 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
		bool	isValidDate(const std::string &date) const;

	public:
		//methods
		void readData(const std::string &infile);
		void readInputFile(const std::string &infile);

		//getter
		float getExchangeRate(const std::string &date) const;

		//constructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		BitcoinExchange &operator=(const BitcoinExchange &original);
		~BitcoinExchange();		
};

#endif // BITCOINEXCHANGE_HPP