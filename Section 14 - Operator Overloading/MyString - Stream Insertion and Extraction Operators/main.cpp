#include <iostream>
#include "mystring.h"
#include <string>
#include <cstring>
using namespace std;

int main()
{
    MyString myFirstName; // No-args Constructor Called
    MyString myLastName; // No-args Constructor Called
    MyString fullName; // No-args Constructor Called

    cout << "Insertion Operator" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Write your first name: ";
    cin >> myFirstName;
    cout << "Write your last name: ";
    cin >> myLastName;

    cout << "Class Methods" << endl;
    cout << "-----------------------------------------------------------" << endl;
    myFirstName = -myFirstName;
    myLastName = -myLastName;
    fullName = myFirstName + " " + myLastName; // MyString Concatenation
    fullName.display();

    if (myFirstName > myLastName)
        cout << "First name is larger than the last name" << endl;

    else
        cout << "Last name is larger than the first name" << endl;
    return 0;
}