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
    string url;
    int runtime;
    string genre;
    double rating;
    string director;
    vector<string> castActors;
    vector<string> descriptionKeyWords;
    int releaseYear;


public:

    Movie(string title = "Blank Title",
           string url = "Blank URL",
          int runtime = 0,
          string genre = "Blank Genre",
          double rating = 0.0,
          string director = "Blank Director",
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
    string getUrl() const;
    int getRuntime() const;
    string getGenre() const;
    double getRating() const;
    string getDirector() const;
    vector<string> getCastActors() const;
    vector<string> getDescriptionKeyWords() const;
    int getReleaseYear() const;
    int getReleaseYear();


};

#endif //COP3530_PROJECT_2_TEAM_14_MOVIE_H
