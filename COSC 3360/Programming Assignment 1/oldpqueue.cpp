#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "huffmanTree.h"
#include "printerfunct.h"
using namespace std;

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(huffmanNode *l, huffmanNode *r)
    {

    if(l->freq == r->freq){
        if(l->character == r->character){
            return l->id < r->id;
        }
        return l->character>r->character;
    }    
    return l->freq>r->freq;
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


// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string filename)
{
    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq =initFile(filename);


    // Create a priority queue to store live nodes of
    // Huffman tree;
    priority_queue<huffmanNode *, vector<huffmanNode *>, comp> pq;


    //herere
    int id=0;
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
        cout << "_________________________________________";

        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        cout << endl
             << "top: " << pq.top()->character << endl;

        huffmanNode *left = pq.top();
        pq.pop();
        cout << "l: " << left->character << ", " << left->freq << " ";
        cout << endl
             << pq.top()->character << endl;

        huffmanNode *right = pq.top();
        pq.pop();
        cout << "r: " << right->character << ", " << right->freq << " ";

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        cout << "s: " << sum << endl;
         auto hi = getNode('\0', sum, left, right,id);
         id++;
        pq.push(hi);

        // pq.push(getNode('\0', sum, left, right));
        cout << endl
             << "top: " << pq.top()->character << endl;
         print2D(hi);
        cout << "_________________________________________";
    }

    // root stores pointer to root of Huffman Tree
    huffmanNode *root = pq.top();
    cout << "root: " << root->character << root->freq<<" "<<
    root->id << endl;

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);


    print_huffman_tree(root, "");


    string str = "011011011101100101";

    // traverse the Huffman Tree again and this time
    // decode the encoded string
    int index = -1;
    cout << "\nOriginal Message: ";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

int main()
{

    string filename = "input2.txt";
    buildHuffmanTree(filename);

    return 0;
}
