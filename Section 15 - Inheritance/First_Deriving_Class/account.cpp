#include "account.h"

// Delegated Constructor
Account::Account(std::string name, double balance)
: name{name}, balance{balance} {
}

// Destructor
Account::~Account() { }


void Account::deposit(double amount)
{
	std::cout << "Deposited: " << amount << std::endl;
	this->balance += amount;
}

void Account::withdraw(double amount)
{
	std::cout << "Withdraw: " << amount << std::endl;
	this->balance -= amount;
}
