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

	// Virtual Trust Account Destructor
	virtual ~Trust_Account() = default;

	// Trust Account class methods
	virtual bool deposit(double amount) override; // Deposits of $5000.00 or more will receive a $50 bonus
	virtual bool withdraw(double amount) override; // Only allowed maximum 3 withdrawals per year, up to 20% of the account's balance
	virtual double get_balance() const override;
	virtual void print(std::ostream &os) const override;
};

#endif // _TRUST_ACCOUNT_H_