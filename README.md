# CSCE 240 Project 4 

## Main 1 - Hamming Distance
The Hamming distance between two strings can be defined as the number of positions at which the corresponding symbols are different. 

For example:

hamming_distance("thisisate**st**", "thisisate**mp**") `== 2` 

hamming_distance("**T**his is a test", "**t**his is a test") `== 1` 

hamming_distance("this is a ", "this is a **test**") `== 4`

1. `void readData(vector<string> &data, string filename)`: 
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that is sent on the command line)
    - The data in this file is in the form: 
    ```
    string 1
    string 2
    string 3
    ...
    ```
    - Each line in the file is pushed to the vector `data` passed into the function. 
2. `void printData(const vector<string> &data)`
   - Prints the data vector in the following form (one string per line): 
   ```
   value 1 
   value 2
   value 3
   ```
4. `vector<int> findMinHamming(const vector<string> & data, string test)`
   - Returns the index of the element in `data` with the smallest hamming distance to the string `test` as well as the distance
   ```
    cherry
    apple
    banana
   ```
   - Then findMinHamming(data, "apply!") would return a vector holding (1, 2) where 1 indicates the index of the match ("apple") and 2 indicates the hamming distance (2)
3. `void printMinDistance(const vector<string> &data, string word, const vector<int> min)`
   - Prints out in the form: "The minimum hamming distance for `word` is `min[1]` (matching word: `data[min[0]]`)"
   - Example data vector, word and output
   data
   ```
   cherry
   apple
   banana
   ```
   word
   ```
   cherries
   ```
   output
   ```
   The minimum hamming distance for cherries is 3 (matching word: cherry)
   ```

The `main()` function will call these functions in the following order: 
1. Call to the `readData` function 
2. Call to the `printData` function
3. Loop through the `data` vector
   - Each time through, a call to thr `findMinHamming` and the `printMinHamming` function occurs
Example output: 
data
```
apple
banana
bananas
apply
grape
apples
```
output:
```
The minimum hamming distance for apple is 1 (matching word: apply)
The minimum hamming distance for banana is 1 (matching word: bananas)
The minimum hamming distance for bananas is 1 (matching word: banana)
The minimum hamming distance for apply is 1 (matching word: apple)
The minimum hamming distance for grape is 4 (matching word: apple)
The minimum hamming distance for apples is 1 (matching word: apple)
```

## Main 2 - Word Search Solver
A popular diversion in the United States, "word find" (or "word search") puzzles ask the player to find each of a given set of words in a table filled with single letters. A word can read horizontally (left or right), vertically (up or down), or along a 45 degree diagonal (in any of the four directions) formed by consecutively adjacent cells of the table; it may wrap around the table’s boundaries, but it must read in the same direction with no zigzagging. The same cell of the table may be used in different words, but, in a given word, the same cell may be used no more than once. 

The program takes in a puzzle and a list of words and return the start and end position of each word in the puzzle if found and an error message if not found.

The following functions are in the `main-sub2.cpp` file
1. `void readPuzzle(vector<vector<char>> &puzzle, string filename)`: 
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that you will send on the command line)
    - The data in this file is in the form: 
    ```
    A  D  D  T
    Q  I  L  L
    R  D  O  O
    ```
    - Each charcter in the file is pushed to the vector `puzzle` passed into the function. 
2. `void readWords(vector<string> &words, string filename)`:
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that you will send on the command line)
    - The data in this file is in the form: 
    ```
    OLD
    ADD
    DOG
    DID
    ARM
    RID
    AIO
    ```
    - Each string in the file is pushed to the vector `words` passed into the function. 
3. `void printPuzzle(const vector<vector<char>> &puzzle)`
   - Prints out the puzzle in the following format:
    ```
    A  D  D  T
    Q  I  L  L
    R  D  O  O
    ```
4. `void printWords(const vector<string> &words)`
   - Prints out the words in the following format:
    ```
    OLD
    ADD
    DOG
    DID
    ARM
    RID
    AIO
    ```
5. `void printLocation(string word, const vector<int> &start, const vector<int> &end, bool found)`
   - Prints out the starting and end location of the `word` only if `found` is true. 
   - If `found` is false, it prints out: "Word `word` not found" (Examples below)
   - Example puzzle and word list followed by output
    ```
    A  D  D  T
    Q  I  L  L
    R  D  O  O
    ```
    word
     ```
    OLD
    ```
    output:
    ```
    Word OLD found at (2, 2) -> (0, 2)
    ```
6. `bool findWord(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end)`
   - Returns true if `word` is found and stores the start location (row, column of the first character) and the end location (row, column of the last character) in the `start` and `end` vectors. 
   - Returns false if `word` is not found 

The `main()` function will call these functions in the following order: 
1. Call to `readPuzzle` function
2. Call to `readWords` function
3. Call to `printPuzzle` function.
4. Call to `printWords` function. 
5. Loop through the `words` vector
  - Each time through, a call to `findWord` and `printLocation` function

Example output: 
puzzle
```
A  D  D  T
Q  I  L  L
R  D  O  O
```
word list
```
OLD
ADD
DOG
DID
ARM
RID
AIO
```
output:
```
Word OLD found at (2, 2) -> (0, 2)
Word ADD found at (0, 0) -> (0, 2)
Word DOG not found
Word DID found at (0, 1) -> (2, 1)
Word ARM was not found
Word RID found at (2, 0) -> (0, 2)
Word AIO found at (0, 0) -> (2, 2)
```
