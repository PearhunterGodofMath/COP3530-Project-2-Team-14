//
// Created by Brady Graham on 3/19/26.
//

#include "Movie.h"

Movie::Movie(string title, string url, int runtime, string genre,
             double rating, string director, vector<string> castActors,
             vector<string> descriptionKeyWords, int releaseYear)
    : title(title), url(url), runtime(runtime), genre(genre),
      rating(rating), director(director), castActors(castActors),
      descriptionKeyWords(descriptionKeyWords), releaseYear(releaseYear) {}

bool Movie::operator<(const Movie& other) const { return title < other.title; }
bool Movie::operator>(const Movie& other) const { return title > other.title; }
bool Movie::operator==(const Movie& other) const { return title == other.title; }
bool Movie::operator<=(const Movie& other) const { return title <= other.title; }
bool Movie::operator>=(const Movie& other) const { return title >= other.title; }

string Movie::getTitle() const { return title; }
string Movie::getUrl() const { return url; }
int Movie::getRuntime() const { return runtime; }
string Movie::getGenre() const { return genre; }
double Movie::getRating() const { return rating; }
string Movie::getDirector() const { return director; }
vector<string> Movie::getCastActors() const { return castActors; }
vector<string> Movie::getDescriptionKeyWords() const { return descriptionKeyWords; }
int Movie::getReleaseYear() const { return releaseYear; }
