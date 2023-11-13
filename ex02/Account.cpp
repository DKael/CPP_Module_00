/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:05:13 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/13 22:03:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created\n";
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed\n";
	Account::_nbAccounts--;
	Account::_totalAmount -= -_amount;
	Account::_totalNbDeposits -= _nbDeposits;
	Account::_totalNbWithdrawals -= _nbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbDeposits << '\n';
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused\n";
		return false;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << '\n';
}

void Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm *tinfo;

	std::time(&timer);
	tinfo = std::localtime(&timer);
	std::cout << "[" << tinfo->tm_year + 1900;
	if (tinfo->tm_mon + 1 >= 10)
		std::cout << tinfo->tm_mon;
	else
		std::cout << 0 << tinfo->tm_mon;
	if (tinfo->tm_mday >= 10)
		std::cout << tinfo->tm_mday;
	else
		std::cout << 0 << tinfo->tm_mday;
	std::cout << '_';
	if (tinfo->tm_hour >= 10)
		std::cout << tinfo->tm_hour;
	else
		std::cout << 0 << tinfo->tm_hour;
	if (tinfo->tm_min >= 10)
		std::cout << tinfo->tm_min;
	else
		std::cout << 0 << tinfo->tm_min;
	if (tinfo->tm_sec >= 10)
		std::cout << tinfo->tm_sec;
	else
		std::cout << 0 << tinfo->tm_sec;
	std::cout << "]";
}
