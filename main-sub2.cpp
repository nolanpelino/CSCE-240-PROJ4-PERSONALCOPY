// Copyright 2021 <Your name here>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



using std::vector;
using std::cout;
using std::string;

void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end);
bool check_right(const vector<vector<char>> & puzzle,
    string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_upper_right(const vector<vector<char>> & puzzle,
 string word, vector<int> &start, vector<int> &end, int, int);
bool check_lower_right(const vector<vector<char>> & puzzle, 
    string word, vector<int> &start, vector<int> &end, int, int);
bool check_below(const vector<vector<char>> & puzzle, string word,
                 vector<int> &start, vector<int> &end, int, int);
bool check_lower_left(const vector<vector<char>> & puzzle, string word,
                     vector<int> &start, vector<int> &end, int, int);
bool check_left(const vector<vector<char>> & puzzle, string word, 
                  vector<int> &start, vector<int> &end, int, int);
bool check_upper_left(const vector<vector<char>> & puzzle,
 string word, vector<int> &start, vector<int> &end, int, int);
bool check_above(const vector<vector<char>> & puzzle, string word,
                 vector<int> &start, vector<int> &end, int, int);

int main(int argc, char **argv) {
  string puzzleFileName;
  string wordsFileName;
  vector<vector<char>> puzzle;
  vector<string> words;
  if (argc != 3) {
    cout << "Usage: ./sub2 puzzle.txt words.txt\n";
    exit(0);
  }
  puzzleFileName = argv[1];
  wordsFileName = argv[2];
  readPuzzle(puzzle, puzzleFileName);
  readWords(words, wordsFileName);
  printPuzzle(puzzle);
  printWords(words);

  for (auto word : words) {
    vector<int> start;
    vector<int> end;
    bool found;
    found = findWord(puzzle, word, start, end);
    printLocation(word, start, end, found);
    end.clear();
    start.clear();
  }
  return 0;
}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
 std::ifstream in(filename);
  char delim(' ');
  string token;
  vector<char> puzRow;
  if (in.is_open()) {
    while(getline(in, token)) {
      for(char &c : token) {
        if (c != ' ')
          puzRow.push_back(c);
      }
      puzzle.push_back(puzRow);
      puzRow.clear();
    }
  }
    in.close();
    return;
}

void readWords(vector<string> &words, string filename) {
  std::ifstream fin(filename);
  string str;
  while (std::getline(fin, str)) {
        words.push_back(str);
  }
  fin.close();
    return;
}

void printPuzzle(const vector<vector<char>> &puzzle) {
  for (vector<char> row : puzzle) {
        for (auto i : row) {
            cout << i << "  ";
        }
        cout << "\n";
    }
    return;
}

void printWords(const vector<string> &words) {
   for (auto it : words) {
    std::cout << it << "\n";
  }
  return;
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
    if(found) {
      std::cout << "Word " << word << " found at (";
      std::cout << start.front() << ", " << start.back() << ") -> (";
      std:cout << end.front() << ", " << end.back() << ")\n";
    } else {
      std::cout << "Word " << word << " not found\n";
    }
    return;
}

bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
  bool found = false;
  for (int i = 0; i < puzzle.size(); i++) {
    for (int j = 0; j < puzzle[i].size(); j++) {
      if (puzzle[i][j] == word[0]){
        found = check_right(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_upper_right(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_lower_right(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_below(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_lower_left(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_left(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_upper_left(puzzle, word, start, end, i, j);
        if (found)   
          return found;
        found = check_above(puzzle, word, start, end, i, j);
        if (found)   
          return found;
      }
    }
  }
  return false;
}
 
bool check_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1);

  if ((j + word.size() - 1) < puzzle[i].size()) {   // Checks for out of bounds, if not, return false
    for (k = j + 1; k < j + word.size(); k++) {
      if (puzzle[i][k] != word[d])
        return false;
      d++;
    }
  } else {
    return false;
  }
  k--;
  start.push_back(i);
  start.push_back(j);
  end.push_back(i);
  end.push_back(k);
  return true;
}

bool check_upper_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1), p(0);
  int z = i - (word.size() - 1);
  if (((j + word.size() - 1) < puzzle[i].size()) && (z >= 0)) {   // Checks for out of bounds
    k = j + 1;
    p = i - 1;
    while (d < word.size()) {
          if (puzzle[p][k] != word[d])
            return false;
          k++;
          p--;
          d++;
    }
  } else {
    return false;
  }
  k--;
  p++;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(k);
  return true;
}

bool check_lower_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1), p(0);

  if (((j + word.size() - 1) < puzzle[i].size()) && (i + word.size() - 1) < puzzle.size()) {   // Checks for out of bounds
    k = j + 1;
    p = i + 1;
    while ((k < j + word.size()) && (p < i + word.size())) {
          if (puzzle[p][k] != word[d])
            return false;
          k++;
          p++;
          d++;
    }
  } else {
    return false;
  }
  k--;
  p--;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(k);
  return true;
}

bool check_below(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int d(1), p(0);

  if ((i + word.size() - 1) < puzzle.size()) {   // Checks for out of bounds
    p = i + 1;
    while (p < i + word.size()) {
          if (puzzle[p][j] != word[d])
            return false;
          p++;
          d++;
    }
  } else {
    return false;
  }
  p--;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(j);
  return true;
}

bool check_lower_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1), p(0);
  int x = (j - word.size());
  if ((x > 0) && (i + word.size() - 1) < puzzle.size()) {   // Checks for out of bounds
    k = j + 1;
    p = i + 1;
    while ((k > j - word.size()) && (p < i + word.size())) {
          if (puzzle[p][k] != word[d])
            return false;
          k--;
          p++;
          d++;
    }
  } else {
    return false;
  }
  k++;
  p--;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(k);
  return true;      
} 

bool check_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1);
  int x = j - (word.size() - 1);
  if (x >= 0) {   // Checks for out of bounds, if not, return false
  k = j - 1;
    while (d < word.size()) {
      if (puzzle[i][k] != word[d])
        return false;
      d++;
      k--;

    }
  } else {
    return false;
  }
  k++;
  start.push_back(i);
  start.push_back(j);
  end.push_back(i);
  end.push_back(k);
  return true;
}

bool check_upper_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k(0), d(1), p(0);
  int x = j - (word.size() - 1);
  int z = i - (word.size() - 1);
  if ((x >= 0) && (z >= 0)) {   // Checks for out of bounds
    k = j - 1;
    p = i - 1;
    while (d < word.size()) {
      if (puzzle[p][k] != word[d])
        return false;
      k--;
      p--;
      d++;
    }
  } else {
    return false;
  }
  
  k++;
  p++;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(k);
  return true;
}

bool check_above(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int d(1), p(0);
  int z = i - (word.size() - 1);
  if (z >= 0) {   // Checks for out of bounds
    p = i - 1;
    while (d < word.size()) {
      if (puzzle[p][j] != word[d])
        return false;
      p--;
      d++;
    }
  } else {
    return false;
  }
  p++;
  
  start.push_back(i);
  start.push_back(j);
  end.push_back(p);
  end.push_back(j);
  return true;      
}



