#include <iostream>
#include <vector>
using namespace std;

class Move
{
private:
	// attributes
	int *data;

public:
	// methods
	void set_value(int d) { *data = d; }
	int get_value() { return *data; }

	Move(int d); // Delegated Constructor
	Move(const Move &source); 	// Copy Constructor
	Move(Move &&source); 	// Move Constructor 
	~Move(); 	// Destructor
};

// Delegated Construtor
Move::Move(int d)
{
	data = new int;
	*data = d;
	cout << "Constructor Called" << endl;
}

// Copy Constructor
Move::Move(const Move &source)
: Move{*source.data} {
	cout << "Copy Constructor Called - Deep Copy for " << *data << endl;
}

// Move Constructor 
// This constructor 'steals' the memory address from the original
// pointer, and sets it to 'nullptr'
// We don't include constant, because we want to modify the source
Move::Move(Move &&source)
: data{source.data} // Copying the pointer
{
	source.data = nullptr;
	cout << "Move Constructor Called - moving resource for " << *data << endl;
}

// Destructor
Move::~Move()
{
	if (data != nullptr)
		cout << "Destructor Called for " << *data << endl;
	else
		cout << "Destructor Called for nullptr" << endl;
}

int main()
{
	// A vector of type Move is created 
	vector<Move> vec;

	// We add a Move object to the end of the vector
	// This object is an r-value, it calls directly the Move Constructor
	// And the Move Constructor will call first the Delegated Constructor
	// At the end of the scope, the Destructor will be called
	vec.push_back(Move{10});

	// The same thing applies for this line of code
	vec.push_back(Move{20});

	return 0;
} //Finally both constructors are deleted