//Section 8
//Mixed Type Expressions

/*
    Ask the user to enter 3 integers
    Calculate the sum of the integers then
    Calculate the average of the 3 integers

    Display the 3 integers entered
    Display the sum of the 3 integers and
    Display the average of the 3 integers
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num1 {0};
    int num2 {0};
    int num3 {0};
    int total {0};
    int numbers {3};
    double average {0};

    cout << "Please enter your first number: ";
    cin >> num1;

    cout << "Please enter your second number: ";
    cin >> num2;

    cout << "Please enter your third number: ";
    cin >> num3;

    total = num1 + num2 + num3;
    average = total / numbers;

    cout << "The average without casting is: " << average << endl;

    average = static_cast<double> (total) / numbers;
    //average = (double) total / numbers; // This is an old style

    cout << "The average with casting is: " << average << endl;

    return 0;
}
