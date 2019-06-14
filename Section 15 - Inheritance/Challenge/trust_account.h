#pragma once
#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "savings_account.h"

/*  Trust Account is a type of Savings Account
	and limits the withdraw from the account
	Withdraw - same as a regular account
*/

class Trust_Account: public Savings_Account
{
	friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
	// These variables are for the Constructor
	static constexpr const char *def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0; // In percentage
	static constexpr int def_withdraws = 0;

	// Constants for withdraw and deposit function
	static constexpr const double deposit_top = 5000.0;
	static constexpr const double deposit_bonus = 50.0;
	static constexpr const int max_num_withdraws = 3;
	static constexpr const double withdraw_percentage = 0.2; // 20%

protected:
	// Savings Account attributes
	int num_withdraws;

public:
	// Delegated Constructor
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate, int num_withdraws = def_withdraws);

	// Trust Account class methods
	bool deposit(double amount);
	bool withdraw(double amount);
};

// Some helper functions. These are not part of the class
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &account, double amount);
void withdraw(std::vector<Trust_Account> &account, double amount);

#endif // _TRUST_ACCOUNT_H_