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
#include "insufficient_funds_exception.h"

int main()
{

	try
	{
		// Illegal Balance Exception
		std::shared_ptr<Account> ptr1 = std::make_shared<Savings_Account>("Angel", -5000, 10.0); // This will finish the 'try' code block
		std::cout << *ptr1 << std::endl;

		// Insufficient Funds Exception
		ptr1->withdraw(100);
	}

	catch(const Illegal_Balance_Exception &exc)
	{
		std::cerr << exc.what() << std::endl; // Displays "Illegal Balance Exception"
	}

	catch(const Insufficient_Funds_Exception &exc)
	{
		std::cerr << exc.what() << std::endl; // Displays Insufficient Funds Exception"	
	}

	try
	{
		// Illegal Balance Exception
		std::unique_ptr<Account> ptr2 = std::make_unique<Check_Account>("Miguel", 1000, 5.0);
		std::cout << *ptr2 << std::endl;

		// Insufficient Funds Exception
		ptr2->withdraw(10000000);
	}

	catch(const Insufficient_Funds_Exception &exc)
	{
		std::cerr << exc.what() << std::endl; // Displays Insufficient Funds Exception"	
	}

	catch(const Illegal_Balance_Exception &exc)
	{
		std::cerr << exc.what() << std::endl; // Displays "Illegal Balance Exception"
	}

	return 0;
}