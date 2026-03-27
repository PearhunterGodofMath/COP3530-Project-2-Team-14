<H1> COP3530 - Project 2 Team #14 - Whiplash: Quite My Tempo Movie Filtering</h1>
## Description

This program loads a large movie dataset from a CSV file and stores it in an AVL Tree data structure. The AVL Tree allows for efficient insertion and balanced storage of movie records.

Then the program allows users to search for movies using multiple filters such as title, genre, rating, director, cast, keywords, runtime, and release year. It supports both **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** traversal methods to retrieve matching results and outputs the elapsed time of the traversal method.

---

## User Input

After the dataset is loaded, the program runs interactively in the terminal. The user is prompted to enter search criteria:

* Title
* Runtime
* Genre
* Ratings
* Director
* Cast Actors
* Description Keywords
* Release Year
* Search Type (BFS or DFS)

### Notes:

* You can leave any field blank to ignore that filter by pressing Enter.
* Enter **0 at any prompt** to exit the program.

---

## Program Output

* If matching movies are found, the program displays:

  * Movie title and link
  * Elapsed time (in milliseconds)
  * Rating (out of 10)
  * Runtime (minutes)
  * Release year
  * Director

* If no matches are found:

  * The program displays:
    "No matching movie found."

* After each search, the user can:

  * Press **Enter** to search again
  * Enter **0** to exit

---

## How to Run the Program

### Requirements

* C++ compiler (supports C++14)
* CMake
* Terminal or command prompt

---

### Using CMake (Recommended)

1. Open a terminal in the project directory. This directory should contain the CMakeLists.txt file.

2. Create a build folder:

   ```
   mkdir build
   cd build
   ```

3. Generate build files:

   ```
   cmake ..
   ```

4. Build the program:

   ```
   make
   ```

5. Run the executable:

   * On Windows:

     ```
     ./COP3530-Project-2-Team-14.exe
     ```

   * On macOS/Linux:

     ```
     ./COP3530-Project-2-Team-14
     ```

---

### Important Notes

* Ensure the file `100k_Movies_dataset.csv` is in the **same directory as the executable** when running the program.
* The program will not run correctly if the dataset file is missing or cannot be opened.
* The dataset is parsed and loaded into the AVL Tree at program startup.

