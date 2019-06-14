#include "account.h"

// No-args Constructor
Account::Account()
: Account{0.0} //delegating constructor 
{

}

// Delegated Constructor
Account::Account(double balance)
: balance{balance} {
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
	if(balance - amount >= 0)
	{
		std::cout << "Withdraw: " << amount << std::endl;
		this->balance -= amount;	
	}

	else
		std::cout << "Insufficient Funds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
	os << "Account Balance: " << account.balance;
	return os;
}