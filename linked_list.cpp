#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next; // Pointing address to next location

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void InsertAtMid(node *&head, int pos, int data)
{
    node *temp = head;
    int c = 1;
    while (c < pos - 1)
    {
        temp = temp->next;
        c++;
    }
    node *nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
}

int main()
{
    node *node1 = new node(12);
    node *head = node1;
    node *tail = node1;

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 16);
    print(head);
    int p;
    cout << "Enter pos: ";
    cin >> p;
    InsertAtMid(head, p, 34);
    print(head);

    return 0;
}