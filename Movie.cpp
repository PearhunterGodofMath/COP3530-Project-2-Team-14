//
// Created by Brady Graham on 3/19/26.
//

#include "Movie.h"

Movie::Movie(string title, string url, int runtime, vector<string> genres,
             double rating, vector<string> director, vector<string> castActors,
             vector<string> descriptionKeyWords, int releaseYear)
    : title(title), url(url), runtime(runtime), genres(genres),
      rating(rating), director(director), castActors(castActors),
      descriptionKeyWords(descriptionKeyWords), releaseYear(releaseYear) {}

// Operators
bool Movie::operator<(const Movie& other) const { return title < other.title; }
bool Movie::operator>(const Movie& other) const { return title > other.title; }
bool Movie::operator==(const Movie& other) const { return title == other.title; }
bool Movie::operator<=(const Movie& other) const { return title <= other.title; }
bool Movie::operator>=(const Movie& other) const { return title >= other.title; }

// Getters
string Movie::getTitle() const { return title; }
string Movie::getUrl() const { return url; }
int Movie::getRuntime() const { return runtime; }
vector<string> Movie::getGenres() const { return genres; }
double Movie::getRating() const { return rating; }
vector<string> Movie::getDirector() const { return director; }
vector<string> Movie::getCastActors() const { return castActors; }
vector<string> Movie::getDescriptionKeyWords() const { return descriptionKeyWords; }
int Movie::getReleaseYear() const { return releaseYear; }
