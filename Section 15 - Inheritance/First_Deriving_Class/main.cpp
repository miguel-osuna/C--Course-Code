#include <iostream>
#include "account.h"
#include "savingaccount.h"
using namespace std;

int main()
{
	// Use the Account Class
	cout << "\n=== Account =============================" << endl;
	Account acc {};
	acc.deposit(2000);
	acc.withdraw(500.0);

	cout << endl;

	Account *p_acc {nullptr};
	p_acc = new Account();
	p_acc->deposit(1000.0);
	p_acc->withdraw(200.0);
	delete p_acc;

	// Use the Savings Account
	cout << "\n=== Savings Account ====================" << endl;
	Saving_Account sav_acc {};
	sav_acc.deposit(2000.0);
	sav_acc.withdraw(500.0);

	cout << endl;
	
	Saving_Account *p_sav_acc {nullptr};
	p_sav_acc->deposit(2000.0);
	p_sav_acc->withdraw(400.0);
	delete p_sav_acc;

	return 0;
}