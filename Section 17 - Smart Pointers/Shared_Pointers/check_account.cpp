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

// Virtual method
bool Check_Account::deposit(double amount)
{
	return Account::deposit(amount);
}

// Virtual method
double Check_Account::get_balance() const
{
	return Account::get_balance();
}

// Virtual method
void Check_Account::print(std::ostream &os) const // Pure virtual function
{
	os << "[Check Account " << this->name << ": Balance: $" << this->balance << ", Fee: $" << this->fee << "]";
}