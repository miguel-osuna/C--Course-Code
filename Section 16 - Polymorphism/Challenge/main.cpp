/*
	Purpose: Create Derived classes implementing Polymorphism
	Author: Miguel Osuna
	Date: 5/28/2019
*/

#include <iostream>
#include <vector>
#include "i_print.h"
#include "account.h"
#include "savings_account.h"
#include "check_account.h"
#include "trust_account.h"
using namespace std;

int main()
{
	// Account miguel{"Miguel", 5000.0}; // Should throw a compile ERROR
	// cout << miguel << endl;

	Check_Account maida{"Maida", 10000.0};
	cout << maida << endl;

	Account *trust = new Trust_Account{"Omar"};
	cout << *trust << endl;
	delete trust;

	Account *p1 = new Check_Account{"Batman", 10000.0};
	Account *p2 = new Savings_Account{"Superman", 2000.0};
	Account *p3 = new Trust_Account{"Flash", 1000.0};

	vector<Account *> accounts {p1, p2, p3};
	display(accounts);
	deposit(accounts, 6000.0);
	withdraw(accounts, 5000.0);
	display(accounts);

	delete p1;
	delete p2;
	delete p3;

	return 0;
}