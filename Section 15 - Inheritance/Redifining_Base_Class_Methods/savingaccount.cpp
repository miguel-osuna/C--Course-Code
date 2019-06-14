#include "savingaccount.h"

// No-args Constructor
Saving_Account::Saving_Account()
: Saving_Account{0.0, 0.0} {
}

// Delegated Constructor
Saving_Account::Saving_Account(double balance, double interest_rate)
: Account{balance}, interest_rate{interest_rate} {
}

// Destructor
Saving_Account::~Saving_Account() { }

// Methods
void Saving_Account::deposit(double amount)
{
	std::cout << "Deposited: " << amount << std::endl;
	amount *= (1 + interest_rate / 100); // The interest rate is converted from percentage
	Account::deposit(amount);
}

// Withdraw is inherited

std::ostream &operator<<(std::ostream &os, const Saving_Account &sav_account)
{
	os << "Savings account balance: " << sav_account.balance << " Interst rate: " << sav_account.interest_rate;
	return os;
}