/*
	Purpose: Using Shared Pointers
	Author: Miguel Osuna
	Date: 5/28/2019
*/

#include <iostream>
#include <vector>
#include <memory>

#include "i_print.h"
#include "account.h"
#include "savings_account.h"
#include "check_account.h"
#include "trust_account.h"

int main()
{
	std::cout << "\n========================" << std::endl;
	std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Miguel", 12000.0, 2.0, 0);
	std::shared_ptr<Account> acc2 = std::make_shared<Check_Account>("Angel", 5000.0, 10);
	std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Osuna", 1000.0, 1.5);

	std::vector<std::shared_ptr<Account>> accounts;
	accounts.push_back(acc1);	// It makes a copy
	accounts.push_back(acc2);	// It makes a copy
	accounts.push_back(acc3);	// It makes a copy

	// Passing by value acc will make another 'shared_ptr' copy
	for(auto acc: accounts)
	{
		std::cout << *acc << std::endl;
		std::cout << "Use count: " << acc.use_count() << std::endl;
	}

	return 0;
}