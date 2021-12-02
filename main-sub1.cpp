// Copyright 2021 Nolan Pelino
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::string;

void readData(vector<string> &data, string filename);
void printData(const vector<string> &data);
vector<int> findMinHamming(const vector<string> & data, string test);
void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min);

int main(int argc, char **argv) {
  string filename;
  vector<string> data;
  if (argc != 2) {
    cout << "Usage: ./sub1 data.txt\n";
    exit(0);
  }
  filename = argv[1];
  readData(data, filename);
  printData(data);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
  std::ifstream fin(filename);
  string str;
  while (std::getline(fin, str)) {
        data.push_back(str);
  }
  fin.close();
}

void printData(const vector<string> &data) {
  for (auto it : data) {
    std::cout << it << "\n";
  }
  return;
}

vector<int> findMinHamming(const vector<string> & data, string test) {
  vector<int> ret; 
  int lowest[data.size()] = {0};
  int closestIndx, lowestHamm(-1);
  int j;
  for (int i = 0; i < data.size(); ++i) {
    j = 0;
    if (test.length() > data[i].length())
        lowest[i] = lowest[i] + (test.length() - data[i].length());
      else if (test.length() < data[i].length())
        lowest[i] = lowest[i] + (data[i].length() - test.length());
    while (j < test.length() && j < data[i].length()) {
        lowest[i] += (test.at(j) != data[i].at(j));
        j++;
    }
  }

  for (int i = 0; i < data.size(); i ++) {
    if ((lowestHamm == -1 || lowest[i] < lowestHamm) && lowest[i] != 0) {
      lowestHamm = lowest[i];
      closestIndx = i;
    }
    if (lowest[i] == 0) {
      lowestHamm = lowest[i];
      closestIndx = i;
      i = data.size() - 1;
    }
  }

 

  ret.push_back(closestIndx);
  ret.push_back(lowestHamm);
  
  return ret;
}

void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {

  std::cout << "The minimum hamming distance for " << word;
  std::cout << " is " << min[1] << " (Matching word: " << data[min[0]] << ")\n";
  return;
}
