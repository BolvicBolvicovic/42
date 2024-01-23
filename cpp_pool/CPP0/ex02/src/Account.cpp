#include <iostream>
#include <ctime>
#include "Account.hpp"

Account::Account( int initial_deposit )	{ makeDeposit(initial_deposit); }
Account::~Account( void )		{}
Account::Account( void ) 		{}

static int	Account::getNbAccounts( void )		{ return _nbAccounts;	}
static int	Account::getTotalAmount( void )		{ return _totalAmount;	}
static int	Account::getNbDeposits( void )		{ return _nbDeposits;	}
static int	Account::getNbWithdrawals( void )	{ return _nbWithdrawals;}
int		Account::checkAmount( void ) const	{ return this->amount;	}

static void	Account::_displayTimestamp( void )
{
	time_t timestamp = time(NULL);
	struct tm *local = localtime(&timestamp);

	std::cout	<< std::setfill('0')
			<< '[' << local->tm_year + 1900
			<< std::setw(2) << local->tm_mon + 1
			<< std::setw(2) << local->tm_mday << "_"
			<< std::setw(2) << local->tm_hour
			<< std::setw(2) << local->tm_min
			<< std::setw(2) << local->tm_sec
			<< "] ";
}

static void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
			<< "total:" << _totalAmount << ";"
			<< "deposits:" << _totalNbDeposits << ";"
			<< "withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:";
	if (this->_amount - withdrawal < 0) { std::cout << "refused" << std::endl;return false;	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return true;
}


void	Account::displayStatus( void ) const
{
_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}
