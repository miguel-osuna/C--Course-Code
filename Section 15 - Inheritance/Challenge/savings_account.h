#pragma once
#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "account.h"

/*  Savings Account is a type of Account
	adds an interest rate
	Withdraw - same as a regular account
	Deposit:
		Amount supplied to deposit will be incremented by (account * int_rate / 100)
		and then updated amount will be deposited
*/

class Savings_Account: public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Savings_Account account);

private:
	// These variables are for the Constructor
	static constexpr const char *def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0; // In percentage

protected:
	// Savings Account attributes
	double int_rate;

public:
	// Delegated Constructor
	Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

	// Savings Account class methods
	bool deposit(double amount);
	// Inherits the withdraw method from the Account class
};

// Some helper functions. These are not part of the class
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &account, double amount);
void withdraw(std::vector<Savings_Account> &account, double amount);

#endif // _SAVINGS_ACCOUNT_H_