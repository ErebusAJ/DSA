# include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){}

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d){
    Node *toAdd = new Node(d);  
    toAdd->next = head;
    head = toAdd;
}

void insertAtTail(Node *&tail, int d){
    Node *toAdd = new Node(d);
    tail->next = toAdd;
    tail = toAdd;
}

void insertAtMid(Node *head, int d, int p){
    Node *toAdd = new Node(d);
    Node *temp = head;
    int ctr = 0;
    while(temp != NULL){
        ctr++;
        if(ctr == p - 1) break;
        temp = temp->next;
    }

    toAdd->next = temp->next;
    temp->next = toAdd;

}

void printLL(Node *&head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int sizeLL(Node *&head){
    Node *temp = head;
    int ctr = 0;
    while(temp != NULL){
        ctr++;
        temp = temp->next;
    }

    return ctr;
}

Node *insertAtEnd(Node *head, int x) {
        Node *toAdd = new Node(x);
        if(head->next == NULL){
            head = toAdd;
            return head;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = toAdd;
        
        return head;
    }

int main(){
    Node *head = new Node();
    // Node *tail = head;


    // insertAtHead(head, 20);
    // insertAtTail(tail, 30);
    // insertAtMid(head, 40, 3);

    // printLL(head);

    // cout << "Size: " << sizeLL(head) << endl;

    Node *newH = insertAtEnd(head, 345);
    printLL(newH);


}