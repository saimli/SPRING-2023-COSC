#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include "huffmanTree.h"

using namespace std;




int main() {
 { // Open the file for reading
  ifstream file("compressed.txt");

  // Check if the file was successfully opened
  if (!file.is_open()) {
    cout << "Could not open file." << endl;
    return 1;
  }

  // Store the data in a vector of pairs, where each pair consists of the first string in each row and a vector of integers corresponding to the rest of the numbers in the row
  vector<pair<string, vector<int>>> data;

  // Read each line in the file
  string line;
  while (getline(file, line)) {
    // Create a stringstream from the line
    stringstream ss(line);

    // Read the first string in the line
    string first;
    ss >> first;

    // Store the rest of the numbers in the line in a vector of integers
    vector<int> numbers;
    int number;
    while (ss >> number) {
      numbers.push_back(number);
    }

    // Add the first string and the vector of numbers to the data
    data.push_back({first, numbers});
  }

  // Close the file
  file.close();

string k;
k.resize(30,' ');
string k1 = "helo";

k.insert(0,k1);
k.insert(7,k1);

//cout<<k.size();
cout<<endl;
  for(int i=0;i<k.size();i++){
      cout<<k[i];
  }
cout<<endl;
// cout<<k<<endl;

  // Print the data
  for (const auto &pair : data) {
    cout << pair.first << ": ";
    string s = pair.first;
    cout<<s<<"     ";
    for (const int &number : pair.second) {
        
      cout << number << " ";
    }
    cout << endl;
  }
 }
  //cout<<endl<<data[1,1];

  return 0;
}
