/*
	Purpose: Using STL Algorithms
	Author: Miguel Osuna
	Date: 6/9/2019
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

void square(int x)
{
	std::cout << x * x << " ";
}

class Player
{
private:
	// Attributes
	std::string name;
	int age;
public:
	// Constructors
	Player() = default;
	Player(std::string name, int age): name{name}, age{age} {}

	// Operators
	bool operator==(const Player &rhs) const;
	bool operator<(const Player &rhs) const;

	// Methods
	std::string get_name() const { return this->name; }
	int get_age() const { return this->age; }
};

bool Player::operator==(const Player &rhs) const
{
	return (this->name == rhs.name && this->age == rhs.age);
}

bool Player::operator<(const Player &rhs) const
{
	return (this->age < rhs.age);
}

int main()
{
	std::vector<int> vec {1, 4, 6, 7, 3};

	// Iterator-less algorithms
	std::cout << "\n================================================" << std::endl;
	std::sort(vec.begin(), vec.end());
	for(auto elem: vec)
		std::cout << elem << std::endl;

	std::cout << "\n================================================" << std::endl;
	std::cout << std::endl;
	std::reverse(vec.begin(), vec.end());
	for(auto elem: vec)
		std::cout << elem << std::endl;

	std::cout << "\n================================================" << std::endl;
	int sum{0};
	sum = std::accumulate(vec.begin(), vec.end(), sum);
	std::cout << "The total is: " << sum << std::endl;

	// Using iterators
	// 'vec.begin()' is the same as 'std::begin(vec)'
	std::cout << "\n================================================" << std::endl;

	// Find algorithm
	std::vector<int>::iterator it = std::find(vec.begin(), std::end(vec), 6);

	if(it != vec.end())
		std::cout << "\nWe found the number: " << *it << std::endl;
	else
		std::cout << "\nSorry, we couldn't find the number" << std::endl;

	// Replace algorithm
	std::replace(vec.begin(), vec.end(), 1, 100);
	for(auto i: vec)
		std::cout << i << " ";

	// Count_if algorithm
	// This time, we use a lambda expression
	std::cout << "\nThere are ";
	int num = std::count_if(vec.begin(), vec.end(), [](int x) { return (x > 2); } );
	std::cout << num << " numbers greater than 2" << std::endl;

	// For_each algorithm
	std::cout << "\nThe square numbers are: ";
	std::for_each(vec.begin(), vec.end(), square);
	std::cout << std::endl;

	// User defined data types
	std::cout << "\n================================================" << std::endl;
	std::vector<Player> players;
	Player regina{"Regina", 256};
	players.push_back(Player{"Miguel", 100});
	players.push_back(Player{"Omar", 50});
	players.push_back(regina);
	players.push_back(Player{"Maida", 70});

	// Find algorithm
	auto player_it = std::find(std::begin(players), players.end(), regina);

	if(player_it != players.end())
		std::cout << "We found the player: " << player_it->get_name() << ", age: " << player_it->get_age() << std::endl;
	else
		std::cout << "We couldn't find the player" << std::endl;

	return 0;
}