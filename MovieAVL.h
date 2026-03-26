//
// Created by dbcam on 3/26/2026.
//

#ifndef COP3530_PROJECT_2_TEAM_14_MOVIEAVL_H
#define COP3530_PROJECT_2_TEAM_14_MOVIEAVL_H

#include "Movie.h"
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Node {
    Movie movie;
    int height;
    Node* left;
    Node* right;

    // Constructor
    Node(Movie movie) {
        this->movie = movie;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class MovieAVL {
private:
    Node* root = nullptr;

    int getHeight(Node* node) const;
    int getBalance(Node* node) const;

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

    Node* insertHelper(Node* node, const Movie& movie);
    void destroyTree(Node* node);

    bool matchesFilters(const Movie& movie,
                        const string& title,
                        const string& runtime,
                        const string& genre,
                        const string& ratings,
                        const string& director,
                        const string& cast,
                        const string& description,
                        const string& releaseYear) const;

    void DFSHelper(Node* node,
                   vector<Movie>& results,
                   const string& title,
                   const string& runtime,
                   const string& genre,
                   const string& ratings,
                   const string& director,
                   const string& cast,
                   const string& description,
                   const string& releaseYear) const;

public:
    void insert(Movie movie);

    // Traversals with filtering
    void BFS(vector<Movie>& results,
             const string& title,
             const string& runtime,
             const string& genre,
             const string& ratings,
             const string& director,
             const string& cast,
             const string& description,
             const string& releaseYear) const;

    void DFS(vector<Movie>& results,
             const string& title,
             const string& runtime,
             const string& genre,
             const string& ratings,
             const string& director,
             const string& cast,
             const string& description,
             const string& releaseYear) const;

    ~MovieAVL();
};

#endif //COP3530_PROJECT_2_TEAM_14_MOVIEAVL_H