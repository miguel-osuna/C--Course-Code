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
#include "illegal_balance_exception.h"

int main()
{

	try
	{
		std::unique_ptr<Account> ptr = std::make_unique<Check_Account>("Miguel", -1000, 5.0);
		std::cout << *ptr << std::endl;
	}

	catch(const Illegal_Balance_Exception &exc)
	{
		std::cerr << "Couldn't create an account" << std::endl;
	}

	return 0;
}