#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "Movie.h"
#include "MovieAVL.h"

using namespace std;

//Helper Functions for CSV File Management

// Split CSV line while handling quotes
vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    string current;
    bool inQuotes = false;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    result.push_back(current);
    return result;
}

// Clean a list like ['Comedy', 'Drama', 'Music']
vector<string> parseList(string field) {
    vector<string> result;

    // Remove brackets
    field.erase(remove(field.begin(), field.end(), '['), field.end());
    field.erase(remove(field.begin(), field.end(), ']'), field.end());
    field.erase(remove(field.begin(), field.end(), '\''), field.end());

    stringstream ss(field);
    string item;

    while (getline(ss, item, ',')) {
        // Trim spaces
        item.erase(0, item.find_first_not_of(" "));
        item.erase(item.find_last_not_of(" ") + 1);
        if (!item.empty()) {
            result.push_back(item);
        }
    }

    return result;
}

// Extract keywords from description
vector<string> extractKeywords(string description) {
    vector<string> words;
    stringstream ss(description);
    string word;

    while (ss >> word) {
        // Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (word.length() > 3) { // ignore small words
            words.push_back(word);
        }
    }

    return words;
}



int main() {
    MovieAVL avl;


    std::string filePath = __FILE__;
    size_t lastSlash = filePath.find_last_of("/\\");
    filePath = filePath.substr(0, lastSlash + 1);

    ifstream file(filePath + "100k_Movies_dataset.csv");


    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    getline(file, line); // skip header

    while (getline(file, line)) {
        vector<string> fields = parseCSVLine(line);

        if (fields.size() < 10) continue;

        string title = fields[0];
        string runtimeStr = fields[2];
        string genreStr = fields[3];
        string ratingStr = fields[4];
        string directorStr = fields[5];
        string castStr = fields[6];
        string description = fields[7];
        string yearStr = fields[8];
        string link = fields[9];

        int runtime = 0;
        if (!runtimeStr.empty()) {
            runtimeStr = runtimeStr.substr(0, runtimeStr.find(" "));
            try { runtime = stoi(runtimeStr); } catch (...) {}
        }

        double rating = 0.0;
        try { rating = stod(ratingStr); } catch (...) {}

        int year = 0;
        try { year = stoi(yearStr); } catch (...) {}

        vector<string> genres = parseList(genreStr);
        vector<string> director = parseList(directorStr);
        vector<string> castActors = parseList(castStr);
        vector<string> keywords = extractKeywords(description);

        Movie movie(title, link, runtime, genres, rating, director, castActors, keywords, year);
        avl.insert(movie);
    }

    cout << "Movies loaded successfully!\n\n";

    while (true) {
        cout << ">>Welcome to Whiplash<<" << endl;
        cout << "What may your goodwill be hunting for today?" << endl;
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
        cout << "Would you like to do a breadth-first search or a depth-first search? (Enter BFS or DFS): ";
        string searchType;
        getline(cin, searchType);
        if (searchType == "0") break;
        cout << "How would you like to sortingCriteria the result (Enter Title, Run Time, Rating, or Release Year): ";
        string sortingCriteria;
        getline(cin, sortingCriteria);
        if (sortingCriteria == "0") break;

        vector<Movie> results;
        clock_t startTime = clock();
        if (searchType == "BFS" || searchType == "bfs") {
            avl.BFS(results, title, runtime, genre, ratings, director, cast, description, releaseYear);
        } else {
            avl.DFS(results, title, runtime, genre, ratings, director, cast, description, releaseYear);
        }
        clock_t endTime = clock();
        int elapsed = (int) (1000.0 * (endTime - startTime) / CLOCKS_PER_SEC);

        if (sortingCriteria == "Title" || sortingCriteria == "TITLE" || sortingCriteria == "title") {
            for (int i = 0; i < results.size() -1; i++) {
                for (int j = 0; j < results.size()-i-1; j++) {
                    if (results[j].getTitle() > results[j+1].getTitle()) {
                        Movie temp = results[j+1];
                        results[j+1] = results[j];
                        results[j] = temp;
                    }
                }
            }
        } else if (sortingCriteria == "Run Time" || sortingCriteria == "RUNTIME" || sortingCriteria == "runtime") {
            for (int i = 0; i < results.size() -1; i++) {
                for (int j = 0; j < results.size()-i-1; j++) {
                    if (results[j].getRuntime() > results[j+1].getRuntime()) {
                        Movie temp = results[j+1];
                        results[j+1] = results[j];
                        results[j] = temp;
                    }
                }
            }
        } else if (sortingCriteria == "Rating" || sortingCriteria == "RATING" || sortingCriteria == "rating") {
            for (int i = 0; i < results.size() -1; i++) {
                for (int j = 0; j < results.size()-i-1; j++) {
                    if (results[j].getRating() < results[j+1].getRating()) {
                        Movie temp = results[j+1];
                        results[j+1] = results[j];
                        results[j] = temp;
                    }
                }
            }
        } else if (sortingCriteria == "Release Year" || sortingCriteria == "RELEASE YEAR" || sortingCriteria == "release year") {
            for (int i = 0; i < results.size() -1; i++) {
                for (int j = 0; j < results.size()-i-1; j++) {
                    if (results[j].getReleaseYear() < results[j+1].getReleaseYear()) {
                        Movie temp = results[j+1];
                        results[j+1] = results[j];
                        results[j] = temp;
                    }
                }
            }
        }


        if (!results.empty()) {
            for (const auto &m: results) {
                cout << endl;
                cout << m.getTitle() << " - " << m.getUrl() << "\t\tElapsed Time: " << elapsed << "ms" << endl;
                cout << m.getRating() << " / 10 stars | " << m.getRuntime() << " minutes | Released in " << m.
                        getReleaseYear() << " | A " << m.getDirector()[0] << " film" << endl;
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
