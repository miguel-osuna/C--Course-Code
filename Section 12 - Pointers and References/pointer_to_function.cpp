#include <iostream>
#include <string>
#include <vector> 
using namespace std;

void double_value(int *);
void add_name(vector<string> *, string newName);
void print(const vector<string> *);

int main()
{
    int value {10};
    cout << "The old number is: " << value << endl;
    double_value(&value);
    cout << "The new number is: " << value << "\n" << endl;

    vector<string> names {"Omar", "Regina", "Maida"};
    string newName {"Miguel"};

    print(&names);
    add_name(&names, newName);
    print(&names);

    return 0;
}

void double_value(int *intPtr)
{
    *intPtr *= 2;
    //*int_ptr = *int_ptr * 2;
    return;
}

void add_name(vector<string> *v, string newName)
{
	(*v).push_back(newName);
	return;
}

void print(const vector<string> *v)
{
	for(auto str: *v)
		cout << str << endl;
	cout << endl;
	return;
}