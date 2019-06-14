#pragma once
#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include "account.h"

class Saving_Account: public Account
{
public:
	// Attributes
	double interest_rate;

	// Delegated Constructor
	Saving_Account(double interest_rate = 0.3);
	// Destructor
	~Saving_Account();

	// Methods
	void deposit(double amount);
	void withdraw(double amount);
};


#endif // _SAVING_ACCOUNT_H_