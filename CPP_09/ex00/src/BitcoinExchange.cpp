/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:15:20 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/01 12:42:18 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incl/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

//methods
void BitcoinExchange::readData(const std::string &infile)
{
	std::ifstream file(infile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open data.csv");	

	std::string line;
	std::getline(file, line);

	while(std::getline(file, line))
	{
		size_t commaIndex = line.find(',');
		if (commaIndex != std::string::npos)
		{
			std::string date = line.substr(0, commaIndex);
			float value = static_cast<float>(std::atof(line.substr(commaIndex + 1).c_str()));
			database[date] = value;
		}
	}
}
void BitcoinExchange::readInputFile(const std::string &infile)
{
	std::ifstream file(infile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");
	
	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
		{
			date = date.substr(0, date.find_last_not_of(" \t") + 1);
			valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));
			try
			{
				float value = std::stof(valueStr);
				if (value < 0 || value > 1000)
					throw std::out_of_range("value out of range");
				
				try
				{
					float rate = getExchangeRate(date);
					std::cout << date << " => " << value << " = " << value * rate << std::endl;
				}
				catch (const std::runtime_error &e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			catch (const std::invalid_argument&)
			{
				std::cout << "Error: not a positive number." << std::endl;
			}
			catch (const std::out_of_range&)
			{
				std::cout << "Error: too large a number." << std::endl;
			}
			} else {
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

//getter
float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator iter = database.upper_bound(date);
	
	if (iter == database.begin())
		throw std::runtime_error("Error: No earlier Date available"); //throw error to not look into the future
	
	--iter;
	return iter->second;
}



//default Constructor
BitcoinExchange::BitcoinExchange()
{}

//copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	*this = original;
}

//copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
	if (this != &original)
	{
		database = original.database;
	}
	return (*this);
}

//destructor
BitcoinExchange::~BitcoinExchange()
{}




