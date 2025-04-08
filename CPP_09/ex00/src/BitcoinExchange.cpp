/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:15:20 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/08 17:56:47 by bschmidt         ###   ########.fr       */
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
			float value = static_cast<float>(atof(line.substr(commaIndex + 1).c_str()));
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
			if (isValidDate(date) == false)
			{
				throw (std::runtime_error("Error: invalid Date => " + line));
			}
			valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));
			try
			{
				std::stringstream ss(valueStr);
				float value;
				ss >> value;
				if (ss.fail())
					throw std::invalid_argument("Invalid float value.");
				if (value < 0)
					throw std::out_of_range("Error: not a positive number.");
				else if (value > 1000)
					throw std::out_of_range("Error: too large a number.");
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
			catch (const std::invalid_argument &e)
			{
				std::cout << e.what() << std::endl;
			}
			catch (const std::out_of_range &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
			else
			{
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

bool BitcoinExchange::isValidDate(const std::string &date) const 
{
	if (date.length() != 10)
		return (0);
	if (date[4] != '-' || date[7] != '-')
		return (0);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		return (0); 
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		return (day <= (isLeapYear ? 29 : 28));
	}
	return (1);
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




