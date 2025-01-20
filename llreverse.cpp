#include <bits/stdc++.h>

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

void deleteNodeAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteNodeAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
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

Node *reverseList(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseList(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node *oddEvenList(Node *head)
{
    Node *even = NULL;
    Node *odd = NULL;
    Node *temp = head;
    Node *eH = NULL;
    Node *oH = NULL;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = temp;
                eH = even;
                temp = temp->next;
                continue;
            }
            even->next = temp;
            even = even->next;
        }
        else
        {
            if (odd == NULL)
            {
                odd = temp;
                oH = odd;
                temp = temp->next;
                continue;
            }
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
    }

    odd->next = eH;
    even->next = NULL;
    return oH;
}

// Nth from last
int findLen(Node *head)
{
    int ctr = 0;
    while (head != nullptr)
    {
        ctr++;
        head = head->next;
    }

    return ctr;
}
Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL || head->next == NULL)
        return head;
    int len = findLen(head);
    int p = len - n;
    int ctr = 1;
    Node *temp = head;
    while (ctr != p)
    {
        temp = temp->next;
        ctr++;
    }
    // if (temp->next->next == NULL)
    //     temp->next = NULL;
    temp->next = temp->next->next;

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 5);

    Node *rev = removeNthFromEnd(head, 2);
    print(rev);
}