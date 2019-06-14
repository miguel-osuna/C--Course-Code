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

// Virtual method
bool Savings_Account::withdraw(double amount)
{
	return Account::withdraw(amount);
}

// Virtual method
double Savings_Account::get_balance() const
{
	return Account::get_balance();
}

// Virtual method
void Savings_Account::print(std::ostream &os) const // Pure virtual function
{
	os << "[Savings Account " << this->name << ": Balance: $" << this->balance << ", Interest rate: " << this->int_rate << "%]";
}