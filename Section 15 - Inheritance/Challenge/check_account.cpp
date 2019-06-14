#include "check_account.h"

// Delegated Constructor
Check_Account::Check_Account(std::string name, double balance, double fee)
: Account{name, balance}, fee{fee} {
}

// Check_Account withdraw adds a fee for every retire
bool Check_Account::withdraw(double amount) 
{
	amount += this->fee;
	return Account::withdraw(amount);
}

// Insertion Overloaded Operator
std::ostream &operator<<(std::ostream &os, const Check_Account &account)
{
	os << "[Savings Account " << account.name << ": " << ", Balance: $" << account.balance << ", Fee: $" << account.fee << "]";
	return os;
}

// Some helper functions. These are not part of the class
void display(const std::vector<Check_Account> &accounts)
{
	std::cout << "\n=======================Check Accounts======================" << std::endl;
	for(const auto &acc: accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Check_Account> &account, double amount)
{
	std::cout << "\n================Depositing to Check Accounts===============" << std::endl;
	for(auto &acc: account)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited: " << amount << " to: " << acc << std::endl;
		else
			std::cout << "Failed Deposit of: " << amount << " to: " << acc << std::endl;
	}
}

void withdraw(std::vector<Check_Account> &account, double amount)
{
	std::cout << "\n=============Withdrawing from Check Accounts==============" << std::endl;\

	for(auto &acc: account)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrawed: " << amount << " from: " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of: " << amount << " from: " << acc << std::endl;
	}
}	
