/*
	Purpose: Demonstrating Static Binding - - Function. 
			 This should only call the 'display' function of Account class
	Author: Miguel Osuna
	Date: 5/29/2019
*/

#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
	void display()
	{
		cout << "In Account::withdraw" << endl;
	}
};

class Check: public Account
{
public:
	void display()
	{
		cout << "In Check::withdraw" << endl;
	}
};

class Savings: public Account
{
public:
	void display()
	{
		cout << "In Savings::withdraw" << endl;
	}
};

class Trust: public Account
{
public:
	void display()
	{
		cout << "In Trust::withdraw" << endl;
	}
};

int main()
{
	cout << "-------Pointers-------" << endl;
	Account *p1 = new Account();
	Account *p2 = new Check();
	Account *p3 = new Savings();
	Account *p4 = new Trust();

	Account *p_arr[] {p1, p2, p3, p4};
	for(auto p: p_arr)
		p->display();

	cout << "\n-------Clean up-------" << endl;
	for(auto p: p_arr)
		delete p;

	return 0;
}