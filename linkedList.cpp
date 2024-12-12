#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int add)
{
    Node *temp = new Node(add);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *&tail, int add)
{
    Node *temp = new Node(add);
    tail->next = temp;
    tail = temp;
}

void insertAtMid(Node *&head, int add, int pos)
{
    Node *temp = head;
    Node *toadd = new Node(add);
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    toadd->next = temp->next;
    temp->next = toadd;
}

void deleteNodeAtHead(Node *&head){
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteNodeAtTail(Node *&head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteNodeAtPos(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        
        Node *todelete = temp->next;
        temp->next = todelete->next;
        todelete->next = NULL;
        delete todelete;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *list = new Node(4);
    Node *head = list;
    Node *tail = list;
    print(head);

    insertAtHead(head, 14);
    print(head);

    insertAtEnd(tail, 20);
    print(head);

    insertAtMid(head, 13, 2);
    print(head);

    deleteNodeAtTail(head);
    print(head);
}