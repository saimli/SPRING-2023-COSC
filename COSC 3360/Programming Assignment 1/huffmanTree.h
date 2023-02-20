using namespace std;

//read in input file and create a map of chars and freqs
unordered_map<char, int> initFile(string filename)
{

	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;

	char character[100];
	int frequency[100];
	int i = 0;
	string line;
	ifstream infile(filename);
	while (getline(infile, line))
	{
		character[i] = line[0];
		frequency[i] = stoi(line.substr(2));
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		freq[character[j]] = frequency[j];
	}
	return freq;
}

//huffman nodes
struct huffmanNode
{
	char character;
	int freq;
	int id;
	huffmanNode *left, *right;
};

//create new huffman node
huffmanNode *getNode(char character, int freq, huffmanNode *left, huffmanNode *right,
					 int id)
{
	huffmanNode *node = new huffmanNode();

	node->character = character;
	node->freq = freq;
	node->left = left;
	node->right = right;
	node->id = id + 1;
	return node;
}

// prints the tree code
void print_huffman_tree(huffmanNode *root, string code)
{

	if (root->left == nullptr && root->right == nullptr)
	{
		cout << "Symbol: " << root->character << ", Frequency: " << root->freq << ", Code: " << code << endl;
	}
	if (root->left != nullptr)
	{
		print_huffman_tree(root->left, code + "0");
	}
	if (root->right != nullptr)
	{
		print_huffman_tree(root->right, code + "1");
	}
}

// traverse the Huffman Tree and decode the encoded string
void decode(huffmanNode *root, int &index, string str)
{
	if (root == NULL)
	{
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->character;
		return;
	}

	index++;

	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}
