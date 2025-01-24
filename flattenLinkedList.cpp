#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *merge(Node *first, Node *second)
    {
        Node *temp = (first->data > second->data) ? second : first;
        Node *head = temp;
        if (temp == first)
            first = first->bottom;
        else
            second = second->bottom;

        while (first != NULL && second != NULL)
        {
            if (first->data > second->data)
            {
                temp->bottom = second;
                second = second->bottom;
            }
            else
            {
                temp->bottom = first;
                first = first->bottom;
            }
            temp = temp->bottom;
        }

        while (first != NULL)
        {
            temp->bottom = first;
            first = first->bottom;
            temp = temp->bottom;
        }
        while (second != NULL)
        {
            temp->bottom = second;
            second = second->bottom;
            temp = temp->bottom;
        }

        return head;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->bottom == NULL)
            return head;
        Node *slow = head;
        Node *fast = head->bottom->bottom;
        while (fast != NULL && fast->bottom != NULL)
        {
            fast = fast->bottom->bottom;
            slow = slow->bottom;
        }

        Node *temp = slow->bottom;
        slow->bottom = NULL;
        Node *first = mergeSort(head);
        Node *second = mergeSort(temp);
        Node *sorted = merge(first, second);

        return sorted;
    }

    Node *flatten(Node *root)
    {
        Node *tempH = root;
        Node *tempV = root;
        while (tempH->next != NULL)
        {
            while (tempV->bottom != NULL)
            {
                tempV = tempV->bottom;
            }
            tempV->bottom = tempH->next;
            tempH = tempH->next;
            tempV = tempH;
        }

        Node *sort = mergeSort(root);

        return sort;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++)
        {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL)
            {
                head = temp;
                pre = temp;
            }
            else
            {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++)
            {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}