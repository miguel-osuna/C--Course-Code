#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include <vector>
#include "i_print.h"
#include "illegal_balance_exception.h"
#include "insufficient_funds_exception.h"

// Abstract Account Class
class Account: public I_Print
{
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

	// Virtual Destructor
	virtual ~Account() = default;

	// Account class pure virtual methods
	virtual bool deposit(double amount) = 0; // Pure virtual function
	virtual bool withdraw(double amount) = 0; // Pure virtual function
	virtual double get_balance() const = 0; // Pure virtual function
	virtual void print(std::ostream &os) const override; 
};

// Some helper functions. These are not part of the class. 
// These functions will work just for Base Class Pointers, and
// Will apply the conept of dynamic binding
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &account, double amount);
void withdraw(std::vector<Account *> &account, double amount);

#endif // _ACCOUNT_H_