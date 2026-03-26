//
// Created by dbcam on 3/26/2026.
//

#include "MovieAVL.h"
#include <algorithm>
#include <iostream>
#include <sstream>

// Private AVL Helper Functions
int MovieAVL::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int MovieAVL::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* MovieAVL::rotateLeft(Node* node) {
    // Perform Rotation
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    // Update Heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));

    return rightChild;
}

Node* MovieAVL::rotateRight(Node* node) {
    // Perform Rotation
    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;

    // Update Heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));

    return leftChild;
}

Node* MovieAVL::rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* MovieAVL::rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Node* MovieAVL::insertHelper(Node* node, const Movie& movie) {

    // Normal BST Insertion
    if (node == nullptr) {
        return new Node(movie);
    }

    if (movie < node->movie) {
        node->left = insertHelper(node->left, movie);
    } else if (movie > node->movie) {
        node->right = insertHelper(node->right, movie);
    }

    // Update Height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get Balance Factor
    int balance = getBalance(node);

    // Rotation Cases

    // If tree is right heavy
    if (balance < -1) {

        // Get Balance Factor of right subtree
        int rightBalance = getBalance(node->right);

        // Right Left case if tree's right subtree is left heavy
        if (rightBalance > 0) {
            return rotateRightLeft(node);
        } else {
            // Right Right case
            return rotateLeft(node);
        }
    } else if (balance > 1) {
        // Else if tree is left heavy
        // Get Balance Factor of left subtree
        int leftBalance = getBalance(node->left);

        // Left Right case if tree's left subtree is right heavy
        if (leftBalance < 0) {
            return rotateLeftRight(node);
        } else {
            // Left Left case
            return rotateRight(node);
        }
    }

    return node;
}

void MovieAVL::destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    // Use a postorder traversal to delete nodes since each node will only get visited once
    destroyTree(node->left);  // Delete left subtree first
    destroyTree(node->right); // Then delete right subtree
    delete node;              // Delete current node last
}


// Public Function Definitions
void MovieAVL::insert(Movie movie) {
    root = insertHelper(root, movie);
}

MovieAVL::~MovieAVL() {
    destroyTree(root); // Start recursion from the root
}
