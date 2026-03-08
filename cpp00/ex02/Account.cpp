#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "closed:" << std::endl;
}


int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
	
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	std::cout << "amount:" << this->_amount 
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" <<std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->_amount 
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	struct tm *date = localtime(&now);

	std::cout << "[" << 1900 + date->tm_year
			<< std::setfill('0') << std::setw(2) << 1 + date->tm_mon
			<< std::setfill('0') << std::setw(2) << date->tm_mday
			<< "_" 
			<< std::setfill('0') << std::setw(2) << date->tm_hour
			<< std::setfill('0') << std::setw(2) << date->tm_min
			<< std::setfill('0') << std::setw(2) << date->tm_sec
			<< "] ";	
}
