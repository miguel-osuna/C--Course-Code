#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	// attributes
	string name;
	int age;
	double weight;
	double height;

public:
	// methods
	void set_name(string name) { this->name = name; }
	void set_age(int age) { this->age = age; }
	void set_weight(double weight) { this->weight = weight; }
	void set_height(double height) { this->height = height; }

	string get_name() const { return name; }
	int get_age() const { return age; }
	double get_weight() const { return weight; }
	double get_height() const { return height; }

	// constructors
	Person(string name = "Not available", int age = 0, double weight = 0.0, double height = 0.0);
};

Person::Person(string name, int age, double weight, double height)
: name{name}, age{age}, weight{weight}, height{height} {
}

void display_person(const Person &source)
{
	cout << "Name: " << source.get_name() << endl;
	cout << "Age: " << source.get_age() << endl;
	cout << "Weight: " << source.get_weight() << endl;
	cout << "Height: " << source.get_height() << endl;
	cout << endl;
}

int main()
{
	// Any try of modifyng the miguel object, will result in 
	// a compiler error
	const Person miguel{"Miguel", 22, 80.23, 1.75};
	display_person(miguel);

	Person regina{"Regina", 15};
	regina.set_name("Maida");
	display_person(regina);

	return 0;
}