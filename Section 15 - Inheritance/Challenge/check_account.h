#pragma once
#ifndef _CHECK_ACCOUNT_H_
#define _CHECK_ACCOUNT_H_
#include "account.h"

class Check_Account: public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Check_Account &account);

private:
	// These constants are for the initializer
	static constexpr const char *def_name = "Unnamed account";
	static constexpr const double def_balance = 0.0;
		// There is a fee for each withdraw made
	static constexpr const double def_fee = 1.50;

protected:
	// The class attributes have to be 'protected' so any Derived class can access them
	double fee;

public:
	// Delegated Constructor
	Check_Account(std::string name = def_name, double balance = def_balance, double fee = def_fee);

	// Check Account Methods
	bool withdraw(double amount); // Check_Account withdraw adds a fee for every retire
	// Inherits the withdraw method from the Account class
};

void display(const std::vector<Check_Account> account);
void deposit(std::vector<Check_Account> account, double amount);
void withdraw(std::vector<Check_Account> account, double amount);

#endif // _CHECK_ACCOUNT_H_