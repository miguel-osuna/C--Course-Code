#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i {0};
	int newScore;

	vector <char> vowelsOne (0); //Vector empty, garbage value
	vector <char> vowelsTwo (5); //Vector with 5 elements initialized to 0
	vector <char> vowelsThree {'a', 'e', 'i', 'o', 'u'}; //Vector with 5 elements

	cout << "\nTesting character vectors: " << endl;
	cout << vowelsTwo[0] << endl; 
	cout << vowelsThree.at(0) << endl; //Vector syntax

	vector <int> scoresOne (0); //Vector empty
	vector <int> scoresTwo (10); //Vector with 10 elements initialized to 0
	vector <int> scoresThree (10,50); //Vector with 10 elements initialized to 50
	vector <int> scoresFour {10, 20, 30, 40, 50}; //Vector with 5 elements

	cout << "\nTesting integer vectors: " << endl;
	cout << scoresTwo[1] << endl;
	cout << scoresThree.at(3) << endl; //Vector syntax
	cout << scoresFour.at(4) << endl;

	cout << "\nPlease enter 10 scores: " << endl;
	for(i = 0; i < 10; i++)
		cin >> scoresTwo.at(i);	

	cout << "Please add a new score: ";
	cin >> newScore;
	scoresTwo.push_back(newScore); //Adds the new score to the end of the vector (11 element)

	for(i = 0; i <= 10; i++)
		cout << scoresTwo.at(i) << endl;

	//We should se an output of 11 elements
	cout << "\nThere are: " << scoresFour.size() << " elements in the scoresFour vector" << endl;

	return 0;
}