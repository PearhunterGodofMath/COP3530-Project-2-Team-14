//
// Created by Brady Graham on 3/19/26.
//

#ifndef COP3530_PROJECT_2_TEAM_14_MOVIE_H
#define COP3530_PROJECT_2_TEAM_14_MOVIE_H
#include <string>
#include <vector>
using namespace std;

class Movie
{

    private:

    string title;
    string ID;
    string url;
    int runtime;
    vector<string> genres;
    double rating;
    vector<string> director;
    vector<string> castActors;
    vector<string> descriptionKeyWords;
    int releaseYear;


public:

    Movie(string title = "Blank Title",
          string ID = "Blank ID",
          string url = "Blank URL",
          int runtime = 0,
          vector<string> genres = {},
          double rating = 0.0,
          vector<string> director = {},
          vector<string> castActors = {},
          vector<string> descriptionKeyWords = {},
          int releaseYear = 0);

    //Operators for comparing movies - alphabetically
    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator<=(const Movie& other) const;
    bool operator>=(const Movie& other) const;

    //All getter methods
    string getTitle() const;
    string getID() const;
    string getUrl() const;
    int getRuntime() const;
    vector<string> getGenres() const;
    double getRating() const;
    vector<string> getDirector() const;
    vector<string> getCastActors() const;
    vector<string> getDescriptionKeyWords() const;
    int getReleaseYear() const;

};

#endif //COP3530_PROJECT_2_TEAM_14_MOVIE_H
