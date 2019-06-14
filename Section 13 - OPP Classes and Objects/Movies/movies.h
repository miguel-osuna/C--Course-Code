#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "movie.h"

class Movies
{
	private:
		std::vector<Movie> movies;
	public:
		Movies();
		~Movies();
		void display_movies();
		bool add_movie(std::string name, std::string rating, int views); // Returns false if the movie is not in the list
		bool view_incremented(std::string); // Returns false if the movie is not in the list
};

void add_movie(Movies &movies, std::string name, std::string rating, int views);
void increment_views(Movies &movies, std::string name);

#endif