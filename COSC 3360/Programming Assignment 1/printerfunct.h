using namespace std;

#define COUNT 10
void print2DUtil(huffmanNode *root, int space)
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
    cout << root->character << "-" << root->freq<<" id:"<<root->id << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(huffmanNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
