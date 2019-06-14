#include <iostream>
using namespace std;

class Base
{
private:
	int value;

public:
	Base() : value{0} {cout << "Base No-args Constructor Called" << endl; }
	Base(int x): value{x} { cout << "int Base Constructor Called" << endl; }
	~Base() { cout << "Base Destructor Called" << endl; }
};

class Derived: public Base
{
private:
	int doubled_value;

public:
	Derived() : Base(), doubled_value{0} {cout << "Derived No-args Constructor Called" << endl; } // Initialize No-args Base Construtor
	Derived(int x): Base(x), doubled_value{x * 2} { cout << "intD gloerived Constructor Called" << endl; } // Initialize Base Construtor
	~Derived() { cout << "Derived Destructor Called" << endl; }
};

int main()
{
	Base base;
	cout << endl;

	Base base2{10};
	cout << endl;

	Derived derived;
	cout << endl;

	Derived derived2{20};
	cout << endl;

	return 0;
}

