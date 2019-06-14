#include "savingaccount.h"

// Delegated Constructor
Saving_Account::Saving_Account(double interest_rate)
: interest_rate{interest_rate} {
}

// Destructor
Saving_Account::~Saving_Account() { }

// Methods
void Saving_Account::deposit(double amount)
{
	std::cout << "Deposited: " << amount << std::endl;
	this->balance += amount;
}

void Saving_Account::withdraw(double amount)
{
	std::cout << "Withdraw: " << amount << std::endl;
	this->balance -= amount;
}