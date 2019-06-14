#include <iostream>
using namespace std;

class Base
{
private:
	int value;

public:
	// Base No-args Constructor
	Base(int x = 0): value{x} { cout << "Base Constructor Called" << endl; }
	~Base() { cout << "Base Destructor Called" << endl; }
};

class Derived: public Base
{
private:
	int doubled_value;

public:
	// Derived No-args Construtor
	Derived(int x = 0) doubled_value{x * 2} { cout << "Derived Constructor Called" << endl; }
	~Derived() { cout << "Derived Destructor Called" << endl; }
};

int main()
{
	Base base;
	cout << endl;
	Derived derived;
	cout << endl;

	return 0;
}

