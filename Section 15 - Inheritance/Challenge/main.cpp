/*
	Purpose: Create a new derived class from the Account class
	Author: Miguel Osuna
	Date: 5/28/2019
*/

#include <iostream>
#include <vector>
#include "account.h"
#include "savings_account.h"
#include "check_account.h"
#include "trust_account.h"
using namespace std;

int main()
{
	cout.precision(2);
	cout << fixed;

	// Accounts
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Miguel"});
	accounts.push_back(Account{"Maida", 1000});
	accounts.push_back(Account{"Regina", 2000});

	display(accounts);
	deposit(accounts, 500.0);
	withdraw(accounts, 600.0);
	display(accounts);

	// Savings Accounts
	vector<Savings_Account> save_accounts;
	save_accounts.push_back(Savings_Account{});
	save_accounts.push_back(Savings_Account{"Xiaomi"});
	save_accounts.push_back(Savings_Account{"Huaweii", 5000.0});
	save_accounts.push_back(Savings_Account{"Sony", 6000.0, 10.0});

	display(save_accounts);
	deposit(save_accounts, 1000.0);
	withdraw(save_accounts, 7000.0);
	display(save_accounts);

	// Check Accounts
	vector<Check_Account> check_accounts;
	check_accounts.push_back(Check_Account{});
	check_accounts.push_back(Check_Account{"Playstation"});
	check_accounts.push_back(Check_Account{"Xbox", 2000});
	check_accounts.push_back(Check_Account{"Nintendo", 1000, 1.50});

	display(check_accounts);
	deposit(check_accounts, 10000.0);
	withdraw(check_accounts, 12000.0);
	display(check_accounts);

	// Trust Accounts
	vector<Trust_Account> trust_accounts;
	trust_accounts.push_back(Trust_Account{});
	trust_accounts.push_back(Trust_Account{"Osuna"});
	trust_accounts.push_back(Trust_Account{"Angulo", 500.0});
	trust_accounts.push_back(Trust_Account{"Gomez", 1000.0, 5.0});
	trust_accounts.push_back(Trust_Account{"Perez", 2000.0, 10.0, 3});

	display(trust_accounts);
	deposit(trust_accounts, 1000.0);
	withdraw(trust_accounts, 100.0);
	display(trust_accounts);

	return 0;
}