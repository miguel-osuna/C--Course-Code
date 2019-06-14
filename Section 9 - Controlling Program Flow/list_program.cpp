/**********************************************
 * Author: Miguel Osuna
 * Purpose: List's Operations
 * Date: 21/3/19
**********************************************/

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector<int> numberList; //Not initialized
    char input {};

    do{

        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "C - Clear all the list" << endl;
        cout << "N - Search for a number in the list" << endl;
        cout << "Q - Quit" << endl;

        cout << "\nEnter your choice: ";
        cin >> input;
        cout << endl;
        input = toupper(input); //We convert the character to upper case

        //Variables needed for the operations
        int number {0};

        //We look for the user's selection
        switch(input)
        {

            case 'P':

                if(numberList.size() != 0)
                {
                    cout << "[ ";
                    for(size_t i{0}; i < numberList.size(); i++)
                        cout << numberList.at(i) << " ";

                    cout << "]" << endl;
                }

                else
                    cout << "[] - the list is empty" << endl;

                break;

            case 'A':

                //int number {0};

                cout << "Enter an integer to add to the list: ";
                cin >> number;

                numberList.push_back(number);
                cout << number << " was added to the list" << endl;

                break;

            case 'M':

                if(numberList.size() != 0)
                {
                    double average {};
                    //int average {0};
                    for(size_t i{0}; i < numberList.size(); i++)
                            average += numberList.at(i) / numberList.size();

                    cout << "The average of the list is: " << average << endl;
                }

                else
                    cout << "Unable to calculate the mean - no data" << endl;

                break;

            case 'S':

                if(numberList.size() != 0)
                {
                    int smallest {};
                    smallest = numberList.at(0);

                    for(size_t i{0}; i < numberList.size(); i++)
                        if(smallest > numberList.at(i))
                            smallest = numberList.at(i);

                    cout << "The smallest number of the list is " << smallest << endl;
                }

                else
                    cout << "Unable to determine the smallest number - list is empty" << endl;

                break;

            case 'L':

                if(numberList.size() != 0)
                {
                    int largest {0};
                    largest = numberList.at(0);

                    for(size_t i{0}; i < numberList.size(); i++)
                        if(largest < numberList.at(i))
                            largest = numberList.at(i);

                    cout << "The largest number of the list is " << largest << endl;
                }

                else
                    cout << "Unable to determine the largest number - list is empty" << endl;

                break;

            case 'C':
                numberList.clear();
                cout << "The list was cleared" << endl;
                break;

            case 'N':

                if(numberList.size() != 0)
                {
                    int cnt {0};
                    cout << "Please enter your number you want: ";
                    cin >> number;

                    for(size_t i{0}; i < numberList.size(); i++)
                        if(numberList.at(i) == number)
                            cnt++;

                    cout << "The number " << number << " was found " << cnt << " times in the list" << endl;
                }

                else
                    cout << "Unable to count your number - list is empty" << endl;

                break;

            case 'Q':

                cout << "Goodbye, thanks for using the program!" << endl;
                break;

            default:
                cout << "Unknown selection, please try again" << endl;
        }

        cout << endl;

    } while(input != 'Q');

    return 0;
}
