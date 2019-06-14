#include "savings_account.h"

// Delegated Constructor
Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
: Account{name, balance}, int_rate{int_rate} {
}

// Savings Account deposit method
bool Savings_Account::deposit(double amount)
{

	amount *= (1 + int_rate / 100);
	return Account::deposit(amount);
}

// Insertion Overloaded Operator
std::ostream &operator<<(std::ostream &os, const Savings_Account account)
{
	os << "[Savings Account " << account.name << ": " << ", Balance: $" << account.balance << ", Interest rate: " << account.int_rate << "%]";
	return os;
}

// Some helper functions. These are not part of the class
void display(const std::vector<Savings_Account> &accounts)
{
	std::cout << "\n=======================Savings Accounts======================" << std::endl;
	for(const auto &acc: accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Savings_Account> &account, double amount)
{
	std::cout << "\n===============Depositing to Savings Accounts================" << std::endl;
	for(auto &acc: account)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited: " << amount << " to: " << acc << std::endl;
		else
			std::cout << "Failed Deposit of: " << amount << " to: " << acc << std::endl;
	}
}

void withdraw(std::vector<Savings_Account> &account, double amount)
{
	std::cout << "\n=============Withdrawing from Savings Accounts================" << std::endl;
	for(auto &acc: account)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrawed: " << amount << " from: " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of: " << amount << " from: " << acc << std::endl;
	}
}