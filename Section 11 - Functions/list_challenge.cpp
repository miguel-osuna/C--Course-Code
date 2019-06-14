/**********************************************
 * Author: Miguel Osuna
 * Purpose: Numbers List and Functions
 * Date: 21/3/19
**********************************************/

#include <iostream>
#include <vector>

using namespace std;

void clearScreen();
void displayMenu();
char readInput();
void chooseOption(char c, vector<int>&);
void printNumbers(const vector<int>&);
void addNumbers(vector<int>&);
void displayAverage(const vector<int>&);
void displaySmallest(const vector<int>&);
void displayLargest(const vector<int>&);
void clearList(vector<int>&);
void searchNumber(const vector<int>&);
void goodbye();
void unknown();

int main()
{
    char input {};
    vector<int> numberList {}; //Not initialized

    do{
        displayMenu();
        input = readInput();
        clearScreen();
        chooseOption(input, numberList);
        cout << endl;
    } while(input != 'Q');

    return 0;
}

//This function clear the console
void clearScreen()
{
    system("CLS");
}

//This function displays the main menu on the console
void displayMenu()
{
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear all the list" << endl;
    cout << "F - Search for a number in the list" << endl;
    cout << "Q - Quit" << endl;

    cout << "\nEnter your choice: ";
}

//This functions read the character from the user's choice
char readInput()
{
    char c {};
    cin >> c;
    cout << endl;
    c = toupper(c); //We convert the character to upper case

    return c;
}

//This function switches the choice that was made from the user
void chooseOption(char c, vector<int> &numberList)
{
    switch(c)
    {
        case 'P': printNumbers(numberList); break;
        case 'A': addNumbers(numberList); break;
        case 'M': displayAverage(numberList); break;
        case 'S': displaySmallest(numberList); break;
        case 'L': displayLargest(numberList); break;
        case 'C': clearList(numberList); break;
        case 'F': searchNumber(numberList); break;
        case 'Q': goodbye(); break;
        default:  unknown();
    }
}

//We display the content of the vector on the console. As parameter we use a constant vector to avoid any modification
//If we tried to print an empty list, we inform the user
void printNumbers(const vector<int> &numberList)
{
    if(numberList.size() != 0)
    {
        cout << "[ ";
        for(size_t i{0}; i < numberList.size(); i++)
            cout << numberList.at(i) << " ";

        cout << "]" << endl;
    }

    else
        cout << "[] - the list is empty" << endl;
}

//We add a number to the vector
//We also display a message to inform the user the number was added
void addNumbers(vector<int> &numberList)
{
    int number {};
    cout << "Enter an integer to add to the list: ";
    cin >> number;

    numberList.push_back(number);
    cout << number << " was added to the list" << endl;
}

//We calculate the average of all the vector's numbers
//Then, we display the result on the console
//If there are no numbers, a message is displayed
void displayAverage(const vector<int> &numberList)
{
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
}

//We find the smallest number in the vector, and then display it
void displaySmallest(const vector<int> &numberList)
{
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
}

//We find the largest number in the vector, and then display it
void displayLargest(const vector<int> &numberList)
{
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
}

//We clear all the content of the list
void clearList(vector<int> &numberList)
{
    numberList.clear();
    cout << "The list was cleared" << endl;
}

//We search how many times is the number entered by the user
//available in the list, and then display it on the console
void searchNumber(const vector<int> &numberList)
{
    if(numberList.size() != 0)
    {
        int cnt {0};
        int number {};
        cout << "Please enter the number you want find: ";
        cin >> number;

        for(size_t i{0}; i < numberList.size(); i++)
            if(numberList.at(i) == number)
                cnt++;

        cout << "The number " << number << " was found " << cnt << " times in the list" << endl;
    }

    else
        cout << "Unable to count your number - list is empty" << endl;
}

void goodbye()
{
    cout << "Goodbye, thanks for using the program!" << endl;
}

void unknown()
{
    cout << "Unknown selection, please try again" << endl;
}
