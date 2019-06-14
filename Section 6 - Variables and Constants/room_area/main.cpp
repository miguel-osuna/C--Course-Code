#include <iostream>

using namespace std;

int main()
{
    float length {0};
    float width {0};
    float area {0};

    cout << "Please enter the length of your room in meters: ";
    cin >> length;

    cout << "Please enter the width of your room in meters: ";
    cin >> width;

    area = length * width;

    cout << "The area of your room is: " << area << " m^2" << endl;

    return 0;
}
