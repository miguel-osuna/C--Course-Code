/**********************************************
 * Author: Miguel Osuna
 * Purpose: Example with Vectors
 * Date: 3/15/19
**********************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Declaring empty vectors
    vector <int> vector1;
    vector <int> vector2;

    //Adding an element to the vectors
    vector1.push_back(10);
    vector2.push_back(20);

    //Displaying content of vectors
    cout << "Vector's 1 content is: " << vector1.at(0) << ", so it's size is of: " << vector1.size() << endl;
    cout << "Vector's 2 content is: " << vector2.at(0) << ", so it's size is of: " << vector2.size() << endl;

    //Adding new values
    vector1.push_back(100);
    vector2.push_back(200);

    //Displaying new outputs
    cout << "\nVector's 1 content is: " << vector1.at(0) << " and " << vector1.at(1) << endl;
    cout << "Vector's 1 size is: " << vector1.size() << endl;

    cout << "\nVector's 2 content is: " << vector2.at(0) << " and " << vector2.at(1) << endl;
    cout << "Vector's 2 size is: " << vector2.size() << endl;

    //Declaring  empty 2-D vector
    vector < vector <int> > vector_2d;

    //Adding vector1 and vector2 to the 2-D vector, using push_back function
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    //Display contents of 2-D vector
    cout << "\nDisplaying contents of 2-D Vector" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    //Changing vector1 value
    vector1.at(0) = 1000;

    //Display contents of 2-D vector to see if there is any difference
    cout << "\nDisplaying 2-D Vector again after changing value from vector1" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    //Display the elements in vector1
    cout << endl;
    cout << vector1[0] << endl;
    cout << vector1[1] << endl;

    return 0;
}
