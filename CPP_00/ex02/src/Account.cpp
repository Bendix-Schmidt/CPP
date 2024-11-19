/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:17:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/29 14:48:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	// construct Account
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";created" << std::endl; 
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
	<< _amount << ";closed" << std::endl;
	// deconstruct Account 
}

void	Account::_displayTimestamp(void)
{
	time_t	result = time(NULL);
	tm*	now = localtime(&result);

	std::cout << std::setfill('0') << "["
			  << std::setw(4) << 1900 + now->tm_year
			  << std::setw(2) << 1 + now->tm_mon
			  << std::setw(2) << now->tm_mday
			  << "_"
			  << std::setw(2) << now->tm_hour
			  << std::setw(2) << now->tm_min
			  << std::setw(2) << now->tm_sec
			  << "] " << std::flush;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount;
	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
	<< ";deposit:" << deposit << ";amount:" << _amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount;
	p_amount = _amount;
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << p_amount << ";withdrawal:refused" 
		<< std::endl;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << p_amount << ";withdrawal:" 
		<< withdrawal << ";amount:" << _amount 
		<< ";nb_withdrawals:" << _nbWithdrawals 
		<< std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";deposits:" << _nbDeposits 
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
