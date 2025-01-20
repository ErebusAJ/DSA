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

ListNode *mergeList(ListNode *first, ListNode *second)
{
    ListNode *temp;
    ListNode *merge = (first->val > second->val) ? second : first;
    temp = merge;
    if (merge == first)
        first = first->next;
    else
        second = second->next;

    while (first != NULL && second != NULL)
    {
        if (first->val > second->val)
        {
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
        else
        {
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }
    }

    while (second != NULL)
    {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }

    while (first != NULL)
    {
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }

    return merge;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *fast = head->next->next;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *newHead = slow->next;
    slow->next = NULL;
    ListNode *first = sortList(head);
    ListNode *second = sortList(newHead);
    ListNode *merge = mergeList(first, second);

    return merge;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tail = head;
    ListNode *sort;

    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    print(head);
    sort = sortList(head);
    print(sort);
}