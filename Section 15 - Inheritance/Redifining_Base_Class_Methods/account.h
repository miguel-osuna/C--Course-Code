#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account
{
	friend std::ostream &operator<<(std::ostream &os, const Account &account);
// We define this as protected, so the Derived class can access the attribute 'balance'
protected:
	// Attributes
	double balance;
public:
	// No-args Constructor
	Account();
	// Delegated Constructor
	Account(double balance);
	// Destructor
	~Account();
	// Methods
	void deposit(double amount);
	void withdraw(double amount);
};

#endif // _ACCOUNT_H_