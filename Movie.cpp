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

bool Movie::operator<(Movie& other) { return title < other.title; }
bool Movie::operator>(Movie& other) { return title > other.title; }
bool Movie::operator==(Movie& other) { return title == other.title; }
bool Movie::operator<=(Movie& other) { return title <= other.title; }
bool Movie::operator>=(Movie& other) { return title >= other.title; }

string Movie::getTitle() { return title; }
string Movie::getUrl() { return url; }
int Movie::getRuntime() { return runtime; }
string Movie::getGenre() { return genre; }
double Movie::getRating() { return rating; }
string Movie::getDirector() { return director; }
vector<string> Movie::getCastActors() { return castActors; }
vector<string> Movie::getDescriptionKeyWords() { return descriptionKeyWords; }
int Movie::getReleaseYear() { return releaseYear; }
