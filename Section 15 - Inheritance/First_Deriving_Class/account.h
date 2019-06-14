#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account
{
public:
	// Attributes
	std::string name;
	double balance;

	// Delegated Constructor
	Account(std::string = "MR. X", double balance = 0.0);
	// Destructor
	~Account();

	// Methods
	void deposit(double amount);
	void withdraw(double amount);
};

#endif // _ACCOUNT_H_