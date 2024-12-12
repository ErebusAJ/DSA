#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node{key, nullptr, nullptr};
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Display the left subtree.
    display(root->left);

    // Display the root node.
    std::cout << root->key << " ";

    // Display the right subtree.
    display(root->right);
}

int main()
{
    Node *root = nullptr;

    // Insert the key 10 into the BST.
    root = insert(root, 10);

    // Insert the key 5 into the BST.
    root = insert(root, 5);

    // Insert the key 15 into the BST.
    root = insert(root, 15);

    display(root);
}