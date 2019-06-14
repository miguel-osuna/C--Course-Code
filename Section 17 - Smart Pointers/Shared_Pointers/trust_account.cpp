#include "trust_account.h"

// Delegated Constructor
Trust_Account::Trust_Account(std::string name, double balance, double int_rate, int num_withdraws)
: Savings_Account{name, balance, int_rate}, num_withdraws{num_withdraws} {
}

// Virtual method
bool Trust_Account::deposit(double amount)
{
	if(amount > deposit_top)
		amount += deposit_bonus;
	return Savings_Account::deposit(amount);
}

// Virtual method
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

// Virtual method
double Trust_Account::get_balance() const
{
	return Account::get_balance();
}

// Virtual method
void Trust_Account::print(std::ostream &os) const // Pure virtual function
{
	os << "[Trust Account " << this->name << ": Balance: $" << this->balance << ", Interest rate: " << this->int_rate << "%, No. Withdraws: " << this->num_withdraws << "]";
}