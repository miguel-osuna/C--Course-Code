/**********************************************
 * Author: Miguel Osuna
 * Purpose: Cents Counter Using Modulus
 * Date: 17/3/19
**********************************************/

#include <iostream>
#define DOLLAR 100
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

using namespace std;

int main()
{
    int cents {0};
    unsigned int dollars {0}; //1 dollar is 100 cents
    unsigned int quarters {0}; // 1 quarter is 25 cents
    unsigned int dimes {0}; //1 dime is 10 cents
    unsigned int nickels {0}; //1 nickel is 5 cents
    unsigned int pennies {0}; //1 penny is 1 cent

    cout << "Please enter your cents: ";
    cin >> cents;

    if(cents >= 0)
    {
        dollars = cents / DOLLAR;
        cents %= DOLLAR;

        quarters = cents / QUARTER;
        cents %= QUARTER;

        dimes = cents / DIME;
        cents %= DIME;

        nickels = cents / NICKEL;
        cents %= NICKEL;

        pennies = cents;

        cout << "\nYou have: " << dollars << " dollars" << endl;
        cout << "\nYou have: " << quarters << " quartes" << endl;
        cout << "\nYou have: " << dimes << " dimes" << endl;
        cout << "\nYou have: " << nickels << " nickels" << endl;
        cout << "\nYou have: " << pennies << " pennies" << endl;
    }

    else
        cout << "You don't have money" << endl;

    return 0;
}
