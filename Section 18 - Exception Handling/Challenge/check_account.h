#pragma once
#ifndef _CHECK_ACCOUNT_H_
#define _CHECK_ACCOUNT_H_
#include "account.h"

// Concrete Class
class Check_Account: public Account
{
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

	// Virtual Check Account Destructor 
	virtual ~Check_Account() = default;

	// Check Account Virtual Methods
	virtual bool withdraw(double amount) override; // Check_Account withdraw adds a fee for every retire
	virtual bool deposit(double amount) override;
	virtual double get_balance() const override;
	virtual void print(std::ostream &os) const override;
};

#endif // _CHECK_ACCOUNT_H_