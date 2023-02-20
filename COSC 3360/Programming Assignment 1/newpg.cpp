#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "huffmanTree.h"
using namespace std;

//for pq
struct CharacterFrequency {
    char character;
    int freq;
};
//for pq
struct Compare {
    bool operator()(CharacterFrequency a, CharacterFrequency b) {
        if (a.freq == b.freq) {
            return a.character > b.character;
        }
        return a.freq > b.freq;
    }
};

//start huffman
struct huffmanNode{
    char character;
    int freq;
    huffmanNode *left, *right;
    huffmanNode(char character, int freq) :
    character(character), freq(freq), left(nullptr), right(nullptr) {}

};


void buildHuffman(std::priority_queue<CharacterFrequency,
 std::vector<CharacterFrequency>, Compare> &pq){
    while(pq.size() > 1){
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();
        auto parent = new huffmanNode('-', left.freq +
        right.freq );
        parent -> left = new huffmanNode(left.character, left.freq);
        parent-> right = new huffmanNode(right.character,right.freq);
        pq.push({'-',parent->freq});
    }
 }

/*
void traverseHuffmanTree(huffmanNode *root, string str) {
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->character << ": " << str << endl;
        return;
    }
    traverseHuffmanTree(root->left, str + "0");
    traverseHuffmanTree(root->right, str + "1");
}
*/
void traverseHuffmanTree(huffmanNode *root, string str) {
    int top = 0;
    if (root->left ) {
        str[top] = 0;
        traverseHuffmanTree(root->left, str + "0");
    }
    if (root->right) {
 
        str[top] = 1;
        traverseHuffmanTree(root->right, str + "1");
}}

int main() {
    std::priority_queue<CharacterFrequency, std::vector<CharacterFrequency>, Compare> pq;



    char character[100];
    int frequency[100];
    int i = 0;
    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if(line[0] == ' ')
            character[i] = ' ';
        else
            character[i] = line[0];
        frequency[i] = stoi(line.substr(2));
        i++;
    }

    for(int j =0;j<i;j++){
    pq.push({character[j],frequency[j]});
}


buildHuffman(pq);

//get root of huffman tree
//auto root = pq.top();
auto root = new huffmanNode('-', pq.top().freq);

pq.pop();


cout<<"root value: "<<root->freq<<endl;
cout<<"root value: "<<root->left->left->character<<endl;

string trav;
traverseHuffmanTree(root,"");

// 0 2
// 2 2
// 3 3
// 6 1
//   3
// C 2
// O 1
// S 2
// P 1
// R 1
// I 1
// N 1
// G 1

    // // now the priority queue is sorted in ascending order of frequency
    // // and for elements with the same frequency, it is sorted in ascending order of ASCII values of the characters
    // while (!pq.empty()) {
    //     auto top = pq.top();
    //     std::cout << top.character << ": " << top.frequency << std::endl;
    //     pq.pop();
    // }

//cout<<endl<<endl<<"start"<<endl;


    return 0;
}
