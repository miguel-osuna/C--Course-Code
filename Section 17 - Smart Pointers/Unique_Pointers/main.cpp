/*
	Purpose: Using Unique Pointers
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
	// Account is an Abstract Class, so we can only use it as pointers
	std::unique_ptr<Account> a1 = std::make_unique<Check_Account>("Miguel", 10000.0, 3.0);
	std::cout << *a1 << std::endl;
	a1->deposit(5000);
	a1->withdraw(1500);
	std::cout << *a1 << std::endl;

	std::vector<std::unique_ptr<Account>> vec;
	vec.push_back(std::move(a1));
	vec.push_back(std::make_unique<Savings_Account>("Osuna", 300.0, 5.0));
	vec.push_back(std::make_unique<Trust_Account>("Omar", 5000.0, 10.0, 1));

	// By reference, because unique_pointers can't have copies
	for(auto &acc: vec)
		std::cout << *acc << std::endl;

	// Getting back the pointer
	a1 = std::move(vec.at(0));
	std::cout << *a1 << std::endl;

	return 0;
}