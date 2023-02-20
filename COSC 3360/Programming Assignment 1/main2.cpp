#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Structure for a node in Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    // Comparison function for priority queue
    bool operator<(const Node& n) const {
        if (freq != n.freq)
            return freq > n.freq;
        return ch > n.ch;
    }
};

// Build Huffman tree
Node* buildHuffmanTree(unordered_map<char, int> freq) {
    priority_queue<Node> q;

    // Create leaf nodes and push to priority queue
    for (auto f : freq) {
        Node* n = new Node();
        n->ch = f.first;
        n->freq = f.second;
        n->left = n->right = NULL;
        q.push(*n);
    }

    // Build Huffman tree
    while (q.size() > 1) {
        Node* left = new Node();
        *left = q.top();
        q.pop();

        Node* right = new Node();
        *right = q.top();
        q.pop();

        Node* parent = new Node();
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        q.push(*parent);
    }

        Node top = q.top();
    q.pop();
    return new Node(top);

}

// Store Huffman codes in a map
void storeHuffmanCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == NULL)
        return;

    if (root->ch != '\0')
        huffmanCode[root->ch] = str;

    storeHuffmanCodes(root->left, str + "0", huffmanCode);
    storeHuffmanCodes(root->right, str + "1", huffmanCode);
}

// Print Huffman codes
void printHuffmanCodes(unordered_map<char, int> freq) {
    // Build Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Store Huffman codes in a map
    unordered_map<char, string> huffmanCode;
    storeHuffmanCodes(root, "", huffmanCode);

    // Print Huffman codes
    for (auto f : freq) {
        cout << f.first << ": " << huffmanCode[f.first] << endl;
    }
}

int main() {
    unordered_map<char, int> freq;
     freq['0'] = 2*48; 
     freq['2'] = 2*50;
     freq['3'] = 3*51;
     freq['6'] = 1*54;
     freq[' '] = 3*32;
     freq['C'] = 2*67;
     freq['O'] = 1*79;
     freq['S'] = 2*83;
     freq['P'] = 1*80;
     freq['R'] = 1*82;
     freq['I'] = 1*73;
     freq['N'] = 1*78;
     freq['G'] = 1*71;



    // freq['A'] = 3;
    // freq['C'] = 3;
    // freq['B'] = 1;
    // freq['D'] = 2;
  vector<pair<string, vector<int>>> data;


    //printHuffmanCodes(freq);
    string full;

    full[1]='A';
    //full[0]='00';
    for(int i =0; i<full.size()+2;i++)
    {
        cout<<full[i]<<" ";
    }


    return 0;
}
