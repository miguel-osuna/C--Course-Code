#include "trust_account.h"

// Delegated Constructor
Trust_Account::Trust_Account(std::string name, double balance, double int_rate, int num_withdraws)
: Savings_Account{name, balance, int_rate}, num_withdraws{num_withdraws} {
}

bool Trust_Account::deposit(double amount)
{
	if(amount > deposit_top)
		amount += deposit_bonus;
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	if((num_withdraws >= max_num_withdraws) || (amount > (balance * withdraw_percentage)))
	{
		std::cout << "Sorry, number of withdraw or amount exceeded" << std::endl;
		return false;
	}
	else
	{
		++num_withdraws;
		return Savings_Account::withdraw(amount);
	}
}

// Insertion Overloaded Operator
std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
	os << "[Trust Account " << account.name << ": " << " Balance: $" << account.balance << ", Interest rate: " << account.int_rate << "%, No. Withdraws: " << account.num_withdraws << "]";
	return os;
}

// Some helper functions. These are not part of the class
void display(const std::vector<Trust_Account> &accounts)
{
	std::cout << "\n=======================Trust Accounts======================" << std::endl;
	for(const auto &acc: accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Trust_Account> &account, double amount)
{
	std::cout << "\n================Depositing to Trust Accounts===============" << std::endl;
	for(auto &acc: account)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited: " << amount << " to: " << acc << std::endl;
		else
			std::cout << "Failed Deposit of: " << amount << " to: " << acc << std::endl;
	}
}

void withdraw(std::vector<Trust_Account> &account, double amount)
{
	std::cout << "\n=============Withdrawing from Trust Accounts==============" << std::endl;\

	for(auto &acc: account)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrawed: " << amount << " from: " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of: " << amount << " from: " << acc << std::endl;
	}
}	