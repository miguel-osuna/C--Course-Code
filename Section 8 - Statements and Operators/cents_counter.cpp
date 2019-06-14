/**********************************************
 * Author: Miguel Osuna
 * Purpose: Cents Counter
 * Date: 17/3/19
**********************************************/

#include <iostream>

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
        //We cast to just get the dollars
        dollars = static_cast<int> (cents) / 100;
        //We take off the dollars from the total cents
        cents -= dollars * 100;

        //We cast to just get the quarters
        quarters = static_cast<int> (cents) / 25;
        //We take off the quarters from the total cents
        cents -= quarters * 25;

        //We cast to just get the dimes
        dimes = static_cast<int> (cents) / 10;
        //We take off the dimes from the total cents
        cents -= dimes * 10;

        //We cast to just get the nickels
        nickels = static_cast<int> (cents) / 5;
        //We take off the nickels from the total cents
        cents -= nickels * 5;

        //We finally stay with the pennies
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
