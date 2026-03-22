#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


int main() {
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

        ifstream file("100k_Movies_dataset.csv");
        string line;
        getline(file, line);
        bool found = false;
        auto trim = [](string s) {
            size_t start = s.find_first_not_of(" \"'");
            size_t end = s.find_last_not_of(" \"'");
            return (start == string::npos) ? "" : s.substr(start, end - start + 1);
        };
        auto contains = [](const string& data, const string& input) {
            return input.empty() || data.find(input) != string::npos;
        };

        clock_t startTime = clock();
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

            if (
                contains(fields[0], title) &&
                contains(fields[2], runtime) &&
                contains(fields[3], genre) &&
                contains(fields[4], ratings) &&
                contains(fields[5], director) &&
                contains(fields[6], cast) &&
                contains(fields[7], description) &&
                contains(fields[8], releaseYear)
            ) {
                found = true;
                clock_t endTime = clock();
                int elapsed = (int)(1000.0 * (endTime - startTime) / CLOCKS_PER_SEC);
                cout << endl;
                cout << fields[0] << " - " << fields[9] << "\t\tElapsed Time: " << elapsed << "ms" << endl;
                cout << fields[4] << " / 10 stars | " << fields[2] << " | Released in " << fields[8] << " | A " << fields[5] << " film" << endl;
                break;
            }
        }
        if (!found) {
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
