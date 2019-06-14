#include <iostream>
#include <vector>
#include <string>
#include "movie.h"
#include "movies.h"
using namespace std;

int main()
{
	// We define a new 'Movies' object
	Movies myMovies;
	myMovies.display_movies();

	// We add different and repeated movies
	add_movie(myMovies, "John Wick", "R", 3);
	add_movie(myMovies, "High School Musical", "G", 1);
	add_movie(myMovies, "Iron Man", "PG-13", 3);
	add_movie(myMovies, "John Wick", "R", 3);

	myMovies.display_movies();

	// We increment the value of views of the movies available and not
	// available in the 'myMovies' object
	increment_views(myMovies, "Deadpool");
	increment_views(myMovies, "Iron Man");

	// Finally, we display all the movies in the 'myMovies' object
	myMovies.display_movies();

	return 0;
}