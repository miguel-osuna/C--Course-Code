#include "account.h"

Account::Account(std::string name, double balance)
: name{name}, balance{balance} {
}

bool Account::deposit(double amount)
{
	bool state;
	if(amount < 0)
		state = false;

	else
	{
		this->balance += amount;
		state = true;
	}
	return state;
}

bool Account::withdraw(double amount)
{
	bool state;
	if(this->balance - amount >= 0)
	{
		this->balance -= amount;
		state = true;
	}
	else
		state = false;
	return state;
}

double Account::get_balance() const
{
	return this->balance;
}

// Insertion Overloaded Operator
std::ostream &operator<<(std::ostream &os, const Account &account)
{
	os << "[Account " << account.name << ": " << ", Balance: $" << account.balance << "]";
	return os;
}

// Some helper functions. These are not part of the class
void display(const std::vector<Account> &accounts)
{
	std::cout << "\n==========================Accounts=========================" << std::endl;
	for(const auto &acc: accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Account> &account, double amount)
{
	std::cout << "\n===================Depositing to Accounts==================" << std::endl;
	for(auto &acc: account)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited: " << amount << " to: " << acc << std::endl;
		else
			std::cout << "Failed Deposit of: " << amount << " to: " << acc << std::endl;
	}
}

void withdraw(std::vector<Account> &account, double amount)
{
	std::cout << "\n================Withdrawing from Accounts==================" << std::endl;
	for(auto &acc: account)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrawed: " << amount << " from: " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of: " << amount << " from: " << acc << std::endl;
	}
}	
