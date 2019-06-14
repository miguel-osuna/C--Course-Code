#pragma once
#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include "account.h"

/* Savings Account Class
	Deposit method increments amount to be deposited by amount * interest_rate percentage
	So a 1000 deposit at 5% interst rate will deposit 1000 + 50 = 1050
*/

class Saving_Account: public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Saving_Account &sav_account);
protected:
	// Attributes
	double interest_rate;
public:
	// No-args Constructor
	Saving_Account();
	// Delegated Constructor
	Saving_Account(double balance, double interest_rate);
	// Destructor
	~Saving_Account();

	// Methods
	void deposit(double amount); // Withdraw is inherited
};


#endif // _SAVING_ACCOUNT_H_