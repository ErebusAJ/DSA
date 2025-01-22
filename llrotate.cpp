#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() {}
    ListNode(int n)
    {
        this->val = n;
        this->next = NULL;
    }

    ~ListNode()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(ListNode *&head, int add)
{
    ListNode *temp = new ListNode(add);
    temp->next = head;
    head = temp;
}

void insertAtEnd(ListNode *&tail, int add)
{
    ListNode *temp = new ListNode(add);
    tail->next = temp;
    tail = temp;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLen(ListNode *head)
{
    int ctr = 0;
    while (head != NULL)
    {
        ctr++;
        head = head->next;
    }

    return ctr;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    ListNode *temp = head;
    int len = getLen(head);
    int stop = len > k ? len - k : k / len;
    int ctr = 0;
    ListNode *rotatedHead;
    while (head != NULL && head->next != NULL)
    {
        if (ctr == stop)
        {
            rotatedHead = head->next;
            head->next = NULL;
            head = rotatedHead;
            continue;
        }
        head = head->next;
        ctr++;

    }

    head->next = temp;

    return rotatedHead;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    ListNode *sort;

    insertAtEnd(tail, 1);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 5);

    print(head);
    sort = rotateRight(head, 4);
    print(sort);
}