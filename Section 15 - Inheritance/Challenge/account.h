#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include <vector>

class Account
{
	friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
	// These variables are for the Constructor
	static constexpr const char *def_name = "Unnamed Account";
	static constexpr double def_balance = 0.0;

protected:
	// The class attributes have to be 'protected' so any Derived class can access them
	std::string name;
	double balance;

public:
	// Delegated Constructor
	Account(std::string name = def_name, double balance = def_balance);

	// Account class methods
	bool deposit(double amount);
	bool withdraw(double amount);
	double get_balance() const;
};

// Some helper functions. These are not part of the class
void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &account, double amount);
void withdraw(std::vector<Account> &account, double amount);

#endif // _ACCOUNT_H_