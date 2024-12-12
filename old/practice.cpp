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
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter to the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    root = buildTree(root);

    cout << endl
         << "Pre-Order: ";
    preorder(root);
    cout << endl
         << "In-Order: ";
    inorder(root);
    cout << endl
         << "Post-Order: ";
    postorder(root);

    cout << endl
         << "Level Order Traversal: " << endl;
    levelordertraversal(root);
}

// 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1