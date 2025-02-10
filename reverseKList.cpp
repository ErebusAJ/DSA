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

ListNode *reverseLL(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseLL(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

ListNode *getKthNode(ListNode *head, int k)
{
    while (head != NULL && k > 1)
    {
        head = head->next;
        k--;
    }

    return head;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevNode = NULL;

    while (temp != NULL)
    {
        ListNode *kNode = getKthNode(temp, k);
        if (kNode == NULL)
        {
            if (prevNode)
                prevNode->next = temp;
            break;
        }

        ListNode *nextNode = kNode->next;
        kNode->next = NULL;
        reverseLL(temp);
        if (temp == head)
        {
            head = kNode;
        }
        else
        {
            prevNode->next = kNode;
        }
        prevNode = temp;
        temp = nextNode;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(8);
    ListNode *tail = head;
    ListNode *sort;

    insertAtEnd(tail, 0);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 0);
    insertAtEnd(tail, 1);
    insertAtEnd(tail, 6);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 5);
    insertAtEnd(tail, 6);

    sort = reverseKGroup(head, 2);
    print(sort);
}