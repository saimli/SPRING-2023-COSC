// Write the implementation of the member functions of the huffmanTree class here.

#include <iostream>
#include <fstream>
#include <string>
#include "huffmanTree.h"
using namespace std;


int main() {
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
    for(int j = 0; j < i; j++){
        cout << character[j] << " " << frequency[j] << endl;
    }
    cout<<endl<<endl;
    	HuffmanCodes(character, frequency, i);



// char space ='6';
// cout<<int(space);


return 0;
}


// minHeapNode->ascii < minHeap->array[(i - 1) / 2]->ascii 
// to minHeapNode->ascii > minHeap->array[(i - 1) / 2]->ascii


// 0: 000
// 2: 001
// I: 0100
// N: 0101
// 6: 0110
// G: 0111
// R: 1000
// O: 10010
// P: 10011
//  : 101
// 3: 110
// C: 1110
// S: 1111


// 0: 000
// 2: 001
// C: 010
// S: 011
// R: 1000
// O: 10010
// P: 10011
//  : 101
// 3: 110
// I: 11100
// N: 11101
// 6: 11110
// G: 11111