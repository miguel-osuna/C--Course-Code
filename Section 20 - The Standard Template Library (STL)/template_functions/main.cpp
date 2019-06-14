#include <iostream>
#include <string>

struct Player
{
	std::string name;
	int health;
	int xp;
	bool operator<(const Player &rhs);
	bool operator>(const Player &rhs);
};

// Less than operator
bool Player::operator<(const Player &rhs)
{
	return (this->health < rhs.health);
}

// Greater than operator
bool Player::operator>(const Player &rhs)
{
	return (this->health > rhs.health);
}

// Insertion operator
std::ostream &operator<<(std::ostream &os, const Player &obj)
{
	os << "Name: " << obj.name << ", Health: " << obj.health << ", XP: " << obj.xp;
	return os;
}

// Single data type max template function
template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

// Single data type min template function
template<typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

// Multiple data types func function template
template<typename T1, typename T2>
void func(T1 a, T2 b)
{
	std::cout << a << " " << b << std::endl;
}

int main()
{
	int a{10}, b{20};
	double c{24.5}, d{23.5};
	char e{'A'}, f{'B'};

	Player p1 {"Miguel", 100, 30};
	Player p2 {"Angel", 200, 0};
	Player p3 = min<Player>(p1, p2);

	std::cout << "\nSingle data type" << std::endl;
	std::cout << "The min is: " << min<int>(a, b) << std::endl;	// 10
	std::cout << "The min is: " << min<double>(c, d) << std::endl;	// 23.5
	std::cout << "The min is: " << min<char>(e, f) << std::endl;	// A
	std::cout << p3.name << " has less health: " << p3.health << std::endl;	// 100

	std::cout << "\nMultiple data types" << std::endl;
	func(a, c);
	func(d, e);
	func(e, p1);

	return 0;
}