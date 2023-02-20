#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "huffmanTree.h"

using namespace std;


// Comparison object to be used to order the heap
struct comp
{
    bool operator()(huffmanNode *l, huffmanNode *r)
    {
        if (l->freq == r->freq)
        {
            if (l->character == r->character)
            {
                return l->id < r->id;
            }
            return l->character > r->character;
        }
        return l->freq > r->freq;
    }
};


// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(huffmanNode *root, string str,
            unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->character] = str;
    }
    encode(root->right, str + "1", huffmanCode);
    encode(root->left, str + "0", huffmanCode);
}


void search(huffmanNode *root, string str, int index){

    if(index > str.size()-1){
        cout<<""<<root->character<<"";
    }
    if(str[index] == '0'){
        //cout<<"0 ";
        search(root->left, str, index + 1);
    }
    if(str[index] == '1'){
        //cout<<"1 ";
        search(root->right, str, index + 1);
    }
    }


char searcher(huffmanNode *root, string str, int index){

    if(index > str.size()-1){
        //ss<< c; 
        //string s = ss.str();
        //cout<< s;
        // cout<<c;
        return root->character;
    }
    if(str[index] == '0'){
        return searcher(root->left, str, index + 1);
    }
    if(str[index] == '1'){
        return searcher(root->right, str, index + 1);
    }
     return '\0';
    }


void compressd(huffmanNode *root, string filename){


    std::ifstream input_file(filename);
    std::vector<std::string> first_words;
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string word;
        if (iss >> word) {
            cout<<"here: ";
            first_words.push_back(word);
            search(root,word,0);
            //cout<<endl<<word<<endl;
            /*while(getline(cin,line)){
                iss>>word;
                cout<<word<<" ";
            }*/
            // if(iss>>word){
            // cout<<endl<<word<<endl;
                
            // }
            iss>>word;
            cout<<endl<<word<<endl;
            iss>>word;
            cout<<endl<<word<<endl;
            string l;
//continue here; read in first string in each line of compressed file and traversed the tree to find the char of that line
//need to do: read the rest of strings in to an array maybe and then while array not empty 'string[array of positions] = word'

            cout<<endl;

        }
    }
//       for(int j =0; j<first_words.size();j++){
//     std::cout<<first_words[j]<<" ";
//   }
}

void example(string filename,huffmanNode *root)
{
          // Open the file for reading
  ifstream file(filename);


  // Store the data in a vector of pairs, where each pair consists of 
  //the first string in each row and a vector of integers corresponding 
  //to the rest of the numbers in the row
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
    
    cout<<endl<<numbers[1]<<endl;
  }

  // Close the file
  file.close();



string full;
full.resize(30,' ');
  // Print the data
  for (const auto &pair : data) {
    // cout << pair.first << ": ";
    string s = pair.first;
    //cout<<s<<"     ";
    for (const int &number : pair.second) {
        //cout << number << " ";
        char yo =searcher(root,s,0);
        //cout<<yo;
        full[number] = yo;
    }
    //cout << endl;
  }



}

struct threaddata{
    huffmanNode *root;
    string first;
    string positions;
};

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string filename)
{
    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq = initFile(filename);

    // Create a priority queue to store live nodes of
    // Huffman tree;
    priority_queue<huffmanNode *, vector<huffmanNode *>, comp> pq;

    // I will use an id stored in each node to track when a node was added
    // to the pq to determine how to prioritize same char same freq nodes
    // correctly; iterating on each node being added to the tree
    int id = 0;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr, id));
        id++;
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        huffmanNode *left = pq.top();
        pq.pop();
        huffmanNode *right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        auto hi = getNode('\0', sum, left, right, id);
        id++;
        pq.push(hi);
        // pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    huffmanNode *root = pq.top();

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    print_huffman_tree(root, "");

vector<threaddata> data;

ifstream file("compressed.txt");

// Read each line in the file
string line;
while (getline(file, line)) {
    // Create a stringstream from the line
    stringstream ss(line);

    // Read the first string in the line
    string first;
    ss >> first;

    // Store the rest of the numbers in the line in a string
    string numbers;
    int number;
    while (ss >> number) {
        numbers += to_string(number) + " ";
    }

    // Remove the trailing space from the numbers string
    if (!numbers.empty()) {
        numbers.pop_back();
    }

    // Create a new Data instance with the first string and the numbers string
    threaddata dataItem;
    dataItem.first = first;
    dataItem.positions = numbers;

    // Add the Data instance to the data vector
    data.push_back(dataItem);
}
cout<<endl;
cout<<data[4].positions<<endl;

/*
     { // Open the file for reading
  ifstream file("compressed.txt");


  // Store the data in a vector of pairs, where each pair consists of 
  //the first string in each row and a vector of integers corresponding 
  //to the rest of the numbers in the row
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

string full;
full.resize(30,' ');
  // Print the data
  for (const auto &pair : data) {
     cout << pair.first << ": ";
    string s = pair.first;
    //cout<<s<<"     ";
    for (const int &number : pair.second) {
        //cout << number << " ";
        char yo =searcher(root,s,0);
        //cout<<yo;
        full[number] = yo;
    }
    //cout << endl;
  }




cout<<"Original message: ";
for(int i =0; i<full.size();i++)
cout<<full[i];
cout<<endl<<endl;
 example("compressed.txt",root);
 
 }
*/

}


int main()
{
    string filename = "input3.txt";
    buildHuffmanTree(filename);

    return 0;
}
