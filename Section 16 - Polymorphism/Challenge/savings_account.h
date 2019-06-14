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

// Concrete Class
class Savings_Account: public Account
{
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

	// Virtual Savings Account Destructor
	virtual ~Savings_Account() = default;

	// Savings Account class methods
	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual double get_balance() const override;
	virtual void print(std::ostream &os) const override;

};

#endif // _SAVINGS_ACCOUNT_H_