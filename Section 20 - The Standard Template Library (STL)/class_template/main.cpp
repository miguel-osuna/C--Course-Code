/*
	Purpose: Template Class Example
	Author: Miguel Osuna
	Date: 8/6/2019
*/

#include <iostream>
#include <string>
#include <vector>

/*
  Template classes are typically completely contained in header files
  So, we would have the templeate class in Item.h and no Item.cpp file
  would be used
 */

template <typename T>
class Item
{
private:
	std::string name;
	T value;
public:
	// Constructor
	Item(std::string name, T value): name{name}, value{value} { }

	// Methods
	std::string get_name() const { return this->name; }
	T get_value() const { return this->value; }
};

// Insertion Operator for Item Class template
template <typename T>
std::ostream &operator<<(std::ostream &os, const Item<T> &obj)
{
	os << obj.get_name() << " " << obj.get_value();
	return os;
}

template <typename T1, typename T2>
struct My_Pair
{
	T1 first;
	T2 second;
};

int main()
{
	std::cout << "\nSingle data type class" << std::endl;
	Item<int> item1 {"Miguel", 100};
	std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

	Item<double> item2 {"Angel", 23.3};
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

	Item<std::string> item3 {"Osuna", "Angulo"};
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

	Item<Item<std::string>> item4 {"Outside - string", {"Inside - string", "Inside - value"} };
	// std::cout << item4.get_name() << " " << item4.get_value().get_name() << " " << item4.get_value().get_value() << std::endl;
	std::cout << item4.get_name() << " " << item4.get_value() << std::endl;

	std::cout << "\nMultiple data type class" << std::endl;
	My_Pair<std::string, int> p1 {"Miguel", 100};
	My_Pair<int, double> numbers{12, 2343.5};

	std::cout << p1.first << ", " << p1.second << std::endl;
	std::cout << numbers.first << ", " << numbers.second << std::endl;
	
	return 0;
}