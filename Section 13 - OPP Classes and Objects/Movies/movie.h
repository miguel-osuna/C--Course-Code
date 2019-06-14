#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
#include <iostream>

class Movie
{
	private:
		// attributes
		std::string name;	// The name of the movie
		std::string rating;	// The movie rating: G, PG, PG-13, R
		int views;			// Number of times the movie has been seen

	public:
		// Delegated Constructor
		Movie(std::string name = "No name", std::string rating = "No rating", int views = 0);
		// Copy Constructor
		Movie(const Movie &source);
		// Destructor
		~Movie();

		// Methods
		void set_name(std::string name) { this->name = name;}
		void set_rating(std::string rating) { this->rating = rating; }
		void set_views(int views) { this->views = views; }
		std::string get_name() { return name; }
		std::string get_rating() { return rating; }
		int get_views() { return views; }
		void increment_views() { ++views; }
		void display_info();
};


#endif //_MOVIE_H_