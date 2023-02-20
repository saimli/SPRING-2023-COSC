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
};

huffmanNode* getNode(char character, int freq, huffmanNode* left, huffmanNode* right)
{
	huffmanNode* node = new huffmanNode();

	node->character = character;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(huffmanNode* l, huffmanNode* r)
	{

        if(l->freq==r->freq){
            if(l->character == r->character){
                return l;
            }
            return l->character > r->character;
        }
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

#define COUNT 10
void print2DUtil(huffmanNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->character<<"-"<<root->freq << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(huffmanNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(huffmanNode* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->character] = str;
	}
	encode(root->right, str + "1", huffmanCode);
	encode(root->left, str + "0", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(huffmanNode* root, int &index, string str)
{
	if (root == NULL) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->character;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}




void print_huffman_tree(huffmanNode* root, string code) {
    if (root->left == nullptr && root->right == nullptr) {
        cout << "Symbol: " << root->character << ", Frequency: " << root->freq << ", Code: " << code << endl;
    }
    if (root->left != nullptr) {
        print_huffman_tree(root->left, code + "0");
    }
    if (root->right != nullptr) {
        print_huffman_tree(root->right, code + "1");
    }
}






// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string filename, string text)
{
	// count frequency of appearance of each character
	// and store it in a map

    unordered_map<char,int>freq;



	char character[100];
    int frequency[100];
    int i = 0;
    string line;
    ifstream infile(filename);
    while (getline(infile, line)) {
        if(line[0] == ' ')
            character[i] = ' ';
        else
            character[i] = line[0];
        frequency[i] = stoi(line.substr(2));
        i++;
    }

    for(int j =0;j<i;j++){
	freq[character[j]] = frequency[j];
}
   
    // Adding key-value pairs using
    // subscript([]) and assignment(=)
    // operators
    // freq['0'] = 2;
    // freq['2'] = 2;
    // freq['3'] = 3;
    // freq['6'] = 1;
    // freq[' '] = 3;
    // freq['C'] = 2;
    // freq['O'] = 1;
    // freq['S'] = 2;
    // freq['P'] = 1;
    // freq['R'] = 1;
    // freq['I'] = 1;
    // freq['N'] = 1;
    // freq['G'] = 1;

// A 3
// C 3
// B 1
// D 2

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<huffmanNode*, vector<huffmanNode*>, comp> pq;





	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}




	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
cout<<"_________________________________________";
        
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
        cout<<endl<<"top: "<<pq.top()->character<<endl;
		huffmanNode *left = pq.top(); pq.pop();
        cout<<"l: "<<left->character<<", "<<left->freq<<" ";
        cout<<endl<<pq.top()->character<<endl;

		huffmanNode *right = pq.top();	pq.pop();
        cout<<"r: "<<right->character<<", "<<right->freq<<" ";

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
        cout<<"s: "<<sum<<endl;
        auto hi=getNode('\0', sum, left, right);
		pq.push(hi);
        cout<<endl<<"top: "<<pq.top()->character<<endl;
    print2D(hi);
cout<<"_________________________________________";

	}

	// root stores pointer to root of Huffman Tree
	huffmanNode* root = pq.top();
    cout<<"root: "<<root->character<<root->freq<<endl;


	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);


	cout << "Huffman Codes are :\n" << '\n';


print_huffman_tree(root,"");

ifstream input("compressed.txt");

string compressed,original_message="";
    while(input>>compressed)
    {
        for(int i=0;i<compressed.size();i++)
        {
            char c=compressed[i];
            for(auto [key,value]:huffmanCode)
            {
                if(value==string(1,c))
                {
                    original_message+=key;
                }
            }
        }
    }
    cout<<"Original message: "<<original_message;


//cout<<character[1];	
 
	// cout << "\nOriginal string was :\n" << text << '\n';
	// // // print encoded string
	 string str = "";
	  for (char ch: text) {
	  	str += huffmanCode[ch];
	  }
	  cout<<str;

	// //cout << "\nEncoded string is :\n" << str << '\n';

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	 int index = -1;
	 cout << "\nDecoded string is: \n";
	 while (index < (int)str.size() - 2) {
	 	decode(root, index, str);
	 }
}

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

string text ="Huffman coding is a data compression algorithm.";
string filename = "input3.txt";
text="AAAAAAAAEEEEEEIIIIOOU";
buildHuffmanTree(filename,text);
 


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

    return 0;
}


struct comp
{
	bool operator()(huffmanNode* l, huffmanNode* r)
	{

        if(l->freq==r->freq){
            if(l->character == r->character ){
                return l;
            }
            return l->character > r->character;
        }
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};