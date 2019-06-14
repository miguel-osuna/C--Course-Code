#include <iostream>

using namespace std;

int main()
{
    // Defining variables
    unsigned int smallRooms {0};
    unsigned int largeRooms {0};
    const unsigned int priceSmallRoom {25};
    const unsigned int priceLargeRoom {35};

    unsigned int cost {0};
    const unsigned int estimate {30};
    const float taxRate {0.06};
    float tax {0};
    float total {0};

    // Greeting and input section
    cout << "Hello, Welcome to Miguel's Carpet Cleaning Service\n" << endl;
    cout << "The price per small room is: $" << priceSmallRoom << endl;
    cout << "The price per large room is: $" << priceLargeRoom << endl;

    cout << "\nHow many small rooms would you like to be cleaned? ";
    cin >> smallRooms;
    cout << "How many large rooms would you like to be cleaned? ";
    cin >> largeRooms;

    // All the needed calculations
    cost = priceSmallRoom * smallRooms + priceLargeRoom * largeRooms;
    tax = taxRate * cost;
    total = tax + cost;

    // Display results
    cout << "\nCost per rooms: $" << cost << endl;
    cout << "Tax of order: $" << tax << endl;
    cout << "===================================================" << endl;
    cout << "Total: $" << total << endl;
    cout << "This estimate is valid for " << estimate << " days" << endl;

    return 0;
}
