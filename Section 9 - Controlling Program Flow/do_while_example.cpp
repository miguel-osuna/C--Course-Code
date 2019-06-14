/**********************************************
 * Author: Miguel Osuna
 * Purpose: Do While Example
 * Date: 3/18/19
**********************************************/

#include <iostream>

using namespace std;

int main()
{
    char userKey {};

    do{
        cout << "------------------" << endl;
        cout << "1: Do this" << endl;
        cout << "2: Do that" << endl;
        cout << "3: Do something else" << endl;
        cout << "Q: Quit" << endl;

        cout << "Please enter your selection: ";
        cin >> userKey;
        cout << endl;

        switch(userKey)
        {
            case '1':
                cout << "You entered number 1, thank you\n" << endl;
                break;

            case '2':
                cout << "You entered number 2, thank you\n" << endl;
                break;

            case '3':
                cout << "You entered number 3, thank you\n" << endl;
                break;

            case 'q':

            case 'Q':
                cout << "Goodbye, thanks for using our program\n" << endl;
                break;

            default:
                cout << "Please enter a valid key or number\n" << endl;
        }
    } while(userKey != 'q' && userKey != 'Q');

    return 0;
}
