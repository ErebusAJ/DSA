#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node() {}

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->previous = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *toAdd = new Node(d);

    if (head == NULL)
    {
        head = toAdd;
        return;
    }

    toAdd->next = head;
    head->previous = toAdd;
    head = toAdd;
}

void insertAtTail(Node *&tail, int d)
{
    Node *toAdd = new Node(d);
    tail->next = toAdd;
    toAdd->previous = tail;
    tail = toAdd;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
}

Node* deleteNode(Node* head, int x) {
        Node *temp = head;
        if(x == 1){
            temp->next->previous = NULL;
            head = temp->next;
            
            return head;
        }
        
        int ctr = 1;
        while(temp->next != NULL){
            if(ctr == x) break;
            ctr++;
            temp = temp->next;
        }
        
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        
        return head;
        
    }

int main()
{
    Node *head = NULL;

    insertAtHead(head, 20);
    insertAtHead(head, 50);
    insertAtHead(head, 60);

    head = deleteNode(head, 3);
    printList(head);
}