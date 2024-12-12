#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data to left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Level order traversal

void levelOrderTraversal(node *root)
{
    queue<node *> q; // Initializign queue data structure
    q.push(root);
    q.push(NULL);

    while (!q.empty()) // Check for empty queue
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) // Seprator
        {
            cout << endl;
            if (!q.empty()) // Check if it has child
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// In order traversal

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    cout << "In-Order:" << endl;
    inorder(root);

    cout << endl
         << "Pre-Order" << endl;
    preorder(root);

    cout << endl
         << "Post-Order" << endl;
    postorder(root);
}