#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Movie.h"
#include "MovieAVL.h"
#include "Movie.cpp"
#include "MovieAVL.cpp"

using namespace std;


int main() {
    MovieAVL avl;
    ifstream file("100k_Movies_dataset.csv");
    string line;
    getline(file, line);
    auto trim = [](const std::string& s) {
        size_t start = s.find_first_not_of(" \"'");
        size_t end = s.find_last_not_of(" \"'");
        if (start == std::string::npos) {
            return std::string("");
        } else {
            return s.substr(start, end - start + 1);
        }
    };
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) {
            if (!field.empty() && field.front() == '"') {
                string rest;
                while (field.back() != '"' && getline(ss, rest, ','))
                    field += "," + rest;
            }
            fields.push_back(trim(field));
        }
        if (fields.size() < 10) continue;
        string title = fields[0];
        string url = fields[9];
        int runtime = 0;
        try { runtime = stoi(fields[2]); } catch (...) {}
        string genre = fields[3];
        double rating = 0.0;
        try { rating = stod(fields[4]); } catch (...) {}
        string director = fields[5];
        vector<string> castActors;
        vector<string> descKeywords;
        int releaseYear = 0;
        try { releaseYear = stoi(fields[8]); } catch (...) {}
        avl.insert(Movie(title, url, runtime, genre, rating, director, castActors, descKeywords, releaseYear));

        
    while (true) {
        cout << ">>Welcome to Whiplash<<" << endl;
        cout << "What may your good will be hunting for today?" << endl;
        cout << "(Press 0 at any prompt to exit)" << endl;

        string title, runtime, genre, ratings, director, cast, description, releaseYear;

        cout << "Title: ";
        getline(cin, title);
        if (title == "0") break;
        cout << "Runtime: ";
        getline(cin, runtime);
        if (runtime == "0") break;
        cout << "Genre: ";
        getline(cin, genre);
        if (genre == "0") break;
        cout << "Ratings: ";
        getline(cin, ratings);
        if (ratings == "0") break;
        cout << "Director: ";
        getline(cin, director);
        if (director == "0") break;
        cout << "Cast Actors: ";
        getline(cin, cast);
        if (cast == "0") break;
        cout << "Description Key Words: ";
        getline(cin, description);
        if (description == "0") break;
        cout << "Release Year: ";
        getline(cin, releaseYear);
        if (releaseYear == "0") break;
        cout << "Would you like to do a breadth first search or depth first search? (Enter BFS or DFS): ";
        string searchType;
        getline(cin, searchType);
        if (searchType == "0") break;

        vector<Movie> results;
        clock_t startTime = clock();
        if (searchType == "BFS" || searchType == "bfs") {
            avl.BFS(results, title, runtime, genre, ratings, director, cast, description, releaseYear);
        } else {
            avl.DFS(results, title, runtime, genre, ratings, director, cast, description, releaseYear);
        }
        clock_t endTime = clock();
        int elapsed = (int)(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC);

        if (!results.empty()) {
            for (const auto& m : results) {
                cout << endl;
                cout << m.getTitle() << " - " << m.getUrl() << "\t\tElapsed Time: " << elapsed << "ms" << endl;
                cout << m.getRating() << " / 10 stars | " << m.getRuntime() << " minutes | Released in " << m.getReleaseYear() << " | A " << m.getDirector() << " film" << endl;
            }
        } else {
            cout << "\nNo matching movie found." << endl;
        }

        cout << "\nPress Enter to search again or 0 to exit: ";
        string again;
        getline(cin, again);
        if (again == "0") break;
        cout << endl;
    }
    cout << "Thanks for visiting Whiplash, enjoy the movie!" << endl;

    return 0;
}
