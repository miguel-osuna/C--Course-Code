#include "account.h"

Account::Account(std::string name, double balance)
: name{name}, balance{balance} {
	if(balance < 0)
		throw Illegal_Balance_Exception{};
}

// Virtual method
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

// Virtual method
bool Account::withdraw(double amount)
{
	bool state;
	if(this->balance - amount >= 0)
	{
		this->balance -= amount;
		state = true;
	}
	else
	{
		state = false;
		throw Insufficient_Funds_Exception{};
	}
	
	return state;
}

// Virtual method
double Account::get_balance() const
{
	return this->balance;
}

// Virtual method
void Account::print(std::ostream &os) const // Pure virtual function
{
	os.precision(2);
	os << std::fixed;
	os << "[Account: " << this->name << ", Balance: $" << this->balance << "]";
}

// Some helper functions. These are not part of the class
// Displays Account objects in a vector of Account object pointers
void display(const std::vector<Account *> &accounts)
{
	std::cout << "\n==========================Accounts=========================" << std::endl;
	for(const auto acc: accounts)
		std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account *> &account, double amount)
{
	std::cout << "\n===================Depositing to Accounts==================" << std::endl;
	for(auto acc: account)
	{
		// Dynamic Binding for Account Pointers
		if(acc->deposit(amount))
			std::cout << "Deposited: " << amount << " to: " << *acc << std::endl;
		else
			std::cout << "Failed Deposit of: " << amount << " to: " << *acc << std::endl;
	}
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account *> &account, double amount)
{
	std::cout << "\n================Withdrawing from Accounts==================" << std::endl;
	for(auto acc: account)
	{
		if(acc->withdraw(amount))
			std::cout << "Withdrawed: " << amount << " from: " << *acc << std::endl;
		else
			std::cout << "Failed Withdrawal of: " << amount << " from: " << *acc << std::endl;
	}
}	
